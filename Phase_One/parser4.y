%{
extern int yyparse();
extern int yylex();

#include <stdio.h>
#include "Types.h"
#include <sstream>
#include <string>
#include <string.h>

extern FILE* yyin;
extern int row, col;

void yyerror(const char* msg) {
    printf("ERROR: Row %d, Col %d, %s\n", row, col, msg);
}

char *identToken;
int numberToken;
int  count_names = 0;

int temp_i = 0;
int if_true_i = 0;
int else_i = 0;
int end_if_i = 0;
int beginloop_i = 0;
int loopbody_i = 0;
int endloop_i = 0;

using namespace std;

struct Symbol {
  std::string name;
  Type type;
};
struct Function {
  std::string name;
  std::vector<Symbol> declarations;
  std::vector<Type> params;
  Type return_type;
};

std::vector <Function> symbol_table;


Function *get_function() {
  int last = symbol_table.size()-1;
  return &symbol_table[last];
}

bool find(std::string &value) {
  Function *f = get_function();
  for(int i=0; i < f->declarations.size(); i++) {
    Symbol *s = &f->declarations[i];
    if (s->name == value) {
      return true;
    }
  }
  return false;
}

bool find_function(std::string value, vector<Type> paramTypes) {
  for (int i = 0; i < symbol_table.size(); i++) {
      if (symbol_table[i].name == value && symbol_table[i].params == paramTypes) return true;
    }
    return false;
}

bool find_function_name(std::string value) {
    for (int i = 0; i < symbol_table.size(); i++) {
      if (symbol_table[i].name == value) return true;
    }
    return false;
}

void add_function_to_symbol_table(std::string &value, Type t) {
  Function f; 
  f.name = value; 
  f.return_type = t;
  symbol_table.push_back(f);
}

int add_param_to_function(Type type) {
    Function* f = get_function();
    f->params.push_back(type);
    return f->params.size() - 1;
}

void add_variable_to_symbol_table(std::string &value, Type t) {
  Symbol s;
  s.name = value;
  s.type = t;
  Function *f = get_function();
  f->declarations.push_back(s);
}

void print_symbol_table(void) {
  printf("symbol table:\n");
  printf("--------------------\n");
  for(int i=0; i<symbol_table.size(); i++) {
    printf("function: %s\n", symbol_table[i].name.c_str());
    for(int j=0; j<symbol_table[i].declarations.size(); j++) {
      printf("  locals: %s\n", symbol_table[i].declarations[j].name.c_str());
    }
  }
  printf("--------------------\n");
}


std::string incrementer(std::string val) {
  std::string new_val;
  
  if (val == "beginloop") {
    new_val = std::string("beginloop") + to_string(beginloop_i) ;
    beginloop_i++;
  }
  else if(val == "endloop"){
    new_val = std::string("endloop") + to_string(endloop_i) ;
    endloop_i++;
  }
  else if(val == "temp"){
    new_val = std::string("temp") + to_string(temp_i) ;
    temp_i++;
  }
  else if(val == "loopbody"){
    new_val = std::string("loopbody") + to_string(loopbody_i) ;
    loopbody_i++;
  }
  else if(val == "if_true"){
    new_val = std::string("if_true") + to_string(if_true_i) ;
    if_true_i++;
  }
  else if(val == "else"){
    new_val = std::string("else") + to_string(else_i) ;
    else_i++;
  }
  else if(val == "end_if"){
    new_val = std::string("end_if") + to_string(end_if_i) ;
    end_if_i++;
  }

  return new_val;
}

%}

%union {
    int val;
    char* name;
    struct Node* cn;
}

%token <name>
    INTEGER STRING ARRAY FUNCTION IF ELSE
    WHILE READ WRITE ELSEIF GTE LTE ISEQ NOTEQ
    AND OR RETURN VAR

%token <name> INT

%nterm <cn> variable start func_decl statements 
    statement var_decl cond loop io assignment 
    return var_type arr_len value set_val 
    exp as mult md factor p values params func_temp
    elseif else conditions condition conditional 
    array func_params index arr_vals named_values
    params_temp func_params_temp

%start start
%define parse.error verbose

%left '+' '-'
%left '*' '/'

%%
start: func_decl {
  $$ = $1;
  // print_symbol_table();
  printf("%s", $$->code.c_str());}
| /*empty*/ {Node* node = new Node; node->name = node->code = ""; $$ = node;}
;

statements: statement statements {
  Node* node = new Node;
  node->code = $1->code + $2->code;
  $$ = node;
} 
| /*empty*/ {$$ = new Node;}
;

statement: var_decl ';' {$$ = $1;}
| cond {$$ = $1;}
| loop {$$ = $1;}
| io ';' {$$ = $1;}
| assignment ';' {$$ = $1;}
| return ';' {$$ = $1;}
| func_params_temp ';' {
    $$ = $1;
  }
;


var_type: INTEGER {$$ = new Node; $$->type = Integer;}
| ARRAY var_type arr_len {$$ = new Node; $$->type = Array; $$->code = $3->code; $$->name = $3->name;}
;

arr_len: variable {$$ = $1;}
| value {$$ = $1;}

var_decl: var_type variable set_val { // Set type
  $$ = $1;
  if ($1->type == Array) {
    $$->code += ".[] " + $2->name + ", " + $1->name + "\n";
  }
  else {$$->code += ". " + $2->name + "\n";}
  $$->code += $3->code;
}
;


assignment: named_values set_val {
  Node* node = new Node;
  // node->code = ". " + string($1->name);
  if (strlen($2->name.c_str()) > 0) {
    node->code = $2->code;
    node->code += $1->code;

    if ($1->type == Array) {
      node->code += "[]= " + $1->name + ", " + $1->index + ", " + $2->name + "\n";
    }
    else {
      node->code += "= " + $1->name + ", " + $2->name + "\n";
    }
  }
  $$ = node; 
}
;

set_val: '=' exp {
  $$ = $2;
}
| /*empty*/ {$$ = new Node;}
;

exp: exp as mult { // Type checking
  Node* res = new Node;
  res->name="addtemp";
  res->code = $3->code;
  res->code += $1->code;
  res->code += ". " + res->name + " \n";	
  res->code += $2->name + " " +  res->name + ", " + $1->name + ", " + $3->name + " \n";
  $$ = res;
  $$->type = Integer;
}
| mult {$$ = $1; $$->type = Integer; }
;

mult: mult md factor {
  Node* res = new Node;
  res->name="multtemp";
  res->code = $3->code;
  res->code += $1->code;
  res->code += ". multtemp\n";
  res->code += $2->name + " " + res->name + ", " + $1->name + ", " + $3->name + " \n";
  $$ = res;
}
| factor {$$ = $1;}
;

factor: p {$$ = $1;} // Uhh figure this out?
| values {$$ = $1;}
;



func_decl: func_temp '[' params ']' '{' statements '}' {
  Node* node = $1;
  node->code += $3->code;
  node->code += $6->code;
  node->code += "endfunc\n";
  $$ = node;
}
| func_temp '[' params ']' '{' statements '}' func_decl {
  Node* node = $1;
  node->code += $3->code;
  node->code += $6->code;
  node->code += "endfunc\n";
  $$ = node;
  $$->code += $8->code;
}
;

func_temp: var_type FUNCTION variable {
  if (find_function_name($3->name)) exit(-1);
  add_function_to_symbol_table($3->name, $1->type);
  $$ = new Node;
  $$->code = "func " + $3->name + "\n";
}
;

params: params_temp ',' params {
  $$ = $1;
  $$->code += $3->code;
}
| params_temp {
  $$ = $1;
}
| /*empty*/ {$$ = new Node;}
;

params_temp: var_type variable {
  if (find($2->name)) {
    printf("Variable redeclaration at row: %d, col: %d\n", row, col);
    exit(-1);
  };

  int paramInd = add_param_to_function($1->type);
  add_variable_to_symbol_table($2->name, Integer);

  Node* node = new Node;
  node->code = ". " + $2->name + "\n";
  node->code += "= " + $2->name + ", $" + to_string(paramInd) + "\n";

  $$ = node;
  $$->type = $1->type;
};


loop: WHILE '[' conditions ']' '{' statements '}' {
  Node* node = new Node;
  Node* loop = new Node;
  Node* end = new Node;

  end->name = incrementer("endloop");
  loop->name = incrementer("loopbody");
  node->name = incrementer("beginloop");
  node->code = ": " + node->name + "\n";
  
  Node* cond = new Node;
  cond = $3;

  node->code += cond->code;
  node->code += "?:= " + loop->name + ", " + cond->name + "\n"; 

  node->code += ":= " + end->name + "\n";
  node->code += ": " +loop->name + " \n";

  node->code += $6->code;

  node->code += ":= " + node->name + "\n";
  node->code += ": " + end->name + "\n";

  $$ = node;
};

conditions: condition { 
  $$ = $1;
}
| condition AND conditions {
  Node* emp = new Node;
  $$ = emp;
}
| condition OR conditions {
  Node* emp = new Node;
  $$ = emp;
};

condition: condition conditional exp {
  Node* res = new Node;

  res->name = incrementer("temp");
  res->code += ". " + res->name + "\n";
  res->code += $2->name + " " + res->name + ", " + $1->name + ", " + $3->name + "\n";
  $$ = res;
}
| exp {
  $$ = $1;
}
| '(' condition conditional exp ')' {
  Node* emp = new Node;
  $$ = emp;
}
;


cond: IF '[' conditions ']' '{' statements '}' elseif {
  Node* node = new Node;
  Node* end = new Node;
  Node* cond = new Node;
  cond = $3;
  Node* elseif = new Node;
  elseif = $8;
  end->name = incrementer("end_if");

  node->name = incrementer("if_true");
  node->code = cond->code;
  node->code += "?:= " + node->name + ", " + cond->name + "\n"; 

  if (strlen($8->name.c_str()) <= 0) { 
    node->code += ": " + node->name + "\n";
    node->code += $6->code;
    node->code += ":= " +end->name + "\n";
  }
  else {
    node->code += ":= " + elseif->name + "\n";
    node->code += ": " + node->name + "\n";
    node->code += $6->code;
    node->code += ":= "+ end->name +"\n";
    node->code += ": " + elseif->name + "\n";
    node->code += $8->code;
  }

  node->code += ": " + end->name +"\n";

  $$ = node;
}
;



elseif: ELSEIF '[' conditions ']' '{' statements '}' elseif {
  Node* emp = new Node;
  $$ = emp;
}
| else {
  $$ = $1;
}
;

else: ELSE '{' statements '}' {
  Node* node = new Node;
  node->name = incrementer("else");
  node->code = $3->code;
  $$ = node;
}
| /*empty*/ {
  Node* emp = new Node;
  $$ = emp;
}
;


conditional: '>' {
  $$ = new Node;
  $$->name = ">";
}
| '<' {
  $$ = new Node;
  $$->name = "<";
}
| GTE {
  $$ = new Node;
  $$->name = ">=";
}
| LTE {
  $$ = new Node;
  $$->name = "<=";
}
| ISEQ {
  $$ = new Node;
  $$->name = "==";
}
| NOTEQ {
  $$ = new Node;
  $$->name = "!=";
}
;

io: READ variable {
  $$ = new Node;
  $$->code = string($2->code);
  $$->code += ".< " + string($2->name) + "\n";
}
| WRITE exp {
  $$ = new Node;
  $$->code = string($2->code);
  $$->code += ".> " + $2->name + "\n";
}
;



return: RETURN exp {
  $$ = $2;
  $$->code += "ret " + $2->name + "\n";
}
;



values: named_values {
  $$ = $1;
  if ($1->type == Array) {
    $$->code += ". valtemp\n";
    $$->code += "=[] valtemp, " + $1->name + ", " + $1->index + "\n";
    $$->name = "valtemp";
    $$->type = Integer;
  }
}
| value {$$ = $1;}
| array {$$ = $1;}
| func_params_temp {$$ = $1;}
; 
named_values: variable {$$ = $1;}
| variable '[' index { // CHECK VAR IS THERE
  $$ = $1;
  $$->type = Array;
  $$->index = $3->name;
}
;

func_params: exp ',' func_params {
  $$ = $1;
  $$->code += "param " + $1->name + "\n";
  $$->code += $3->code;
  $$->paramTypes = $3->paramTypes;
  $$->paramTypes.insert($$->paramTypes.begin(), $1->type);
}
| exp ')' {
  $$ = $1;
  $$->code += "param " + $1->name + "\n";
  $$->paramTypes.push_back($1->type);
}
| ')' {$$ = new Node; $$->code = "";} 
;
func_params_temp: variable '(' func_params { // Check return types
  print_symbol_table();
  $$ = new Node;
  $$->code = ". temp0\n";
  $$->code += $3->code;
  $$->code += "call " + $1->name + ", temp0\n";
  $$->name = "temp0";
  if (!find_function($1->name, $3->paramTypes)) {
    printf("No valid function with provided parameters row: %d, col: %d\n", row, col);
    exit(-1);
  }
}
;
p: '(' exp ')' {$$ = $2;}
;
md: '*' {$$ = new Node; $$->name = "*";}
|'/' {$$ = new Node; $$->name = "/";}
;
as: '+' {$$ = new Node; $$->name = "+";}
| '-' {$$ = new Node; $$->name = "-";}
;
variable: VAR {$$ = new Node; $$->name = $1;}
;
index: value ']' {
  $$ = $1;
}
;
value: INT {
  $$ = new Node;
  // $$->code = ". inttemp\n";
  // $$->name = "inttemp";
  // $$->code += "= inttemp, " + string($1) + "\n";
  $$->name = string($1);
  $$->type = Integer;
}
;
array: '{' arr_vals '}' {printf("array -> {arr_vals}\n");}
| '{' '}' {printf("array -> {}\n");}
;
arr_vals: values ',' arr_vals {printf("arr_vals -> values, arr_vals\n");}
| values {printf("arr_vals -> values\n");}
;
%%

int main(int argc, char *argv[]) {
    if (argc > 1) yyin = fopen(argv[1], "r");
    else yyin = stdin;

    yyparse();
    //printf("s\n", $$);
    return 0;
}
