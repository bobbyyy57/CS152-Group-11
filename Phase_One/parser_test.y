%{
    extern int yyparse();
    extern int yylex();
   
    #include <stdio.h>
    #include <string>
    #include <vector>
    #include <string.h>
    #include "Node.h"

    using namespace std;
    
    extern FILE* yyin;
    extern int row, col;

    void yyerror(const char* msg) {
        printf("ERROR: Row %d, Col %d, %s\n", row, col, msg);
    }

    enum Type { Integer, Array };
    struct Symbol {
    string name;
    Type type;
    };
    struct Function {
    string name;
    vector<Symbol> declarations;
    };

    vector <Function> symbol_table;


    Function *get_function() {
    int last = symbol_table.size()-1;
    return &symbol_table[last];
    }

    bool find(string &value) {
    Function *f = get_function();
    for(int i=0; i < f->declarations.size(); i++) {
        Symbol *s = &f->declarations[i];
        if (s->name == value) {
        return true;
        }
    }
    return false;
    }

    void add_function_to_symbol_table(string &value) {
    Function f; 
    f.name = value; 
    symbol_table.push_back(f);
    }

    void add_variable_to_symbol_table(string &value, Type t) {
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

    bool start = true;

%}


%union {
    int val;
    char* name;
    struct Node* cn;
}

%token <name>
    INTEGER STRING ARRAY FUNCTION IF ELSE
    WHILE READ WRITE ELSEIF GTE LTE ISEQ NOTEQ
    AND OR RETURN VAR MAIN

%token <val> INT

%nterm <cn> variable start func_decl statements 
    statement var_decl cond loop io assignment 
    return var_type arr_len value set_val 
    exp as mult md factor p values params
    elseif else conditions condition conditional 
    array func_params index arr_vals

%start start

%left '+' '-'
%left '*' '/'

%%

start: func_decl {
    Node *one = $1;
    $$ = one;
    printf("%s\n", $1->code.c_str());
} | %empty {
    Node* node = new Node;
    $$ = node;

};

func_decl: var_type FUNCTION variable '[' params ']' '{' statements '}' {
        Node *res = new Node();
        string varName = $3->name;

        res->code += "func " + varName + " \n";

        $$ = res;
    /*
    
    Node* one = $3;

    Node* res = new Node();
    res->code = "param " + $3->code;
    $$ = res;
    string func_name = $2;
    add_function_to_symbol_table(func_name);

    */
}
| var_type FUNCTION variable '[' params ']' '{' statements '}' func_decl {
    printf("ADSFADSFAD");
}
;

variable: VAR {
    $$ = new Node();
    $$->name = $1;
};

params: var_decl ',' params {
    printf("PARAMS 1 ");
    Node* one = new Node;
    one->code = "PARAMS";
    $$ = one;
}
| var_decl {
    printf("PARAMS -> VAR_DECL ");
    Node* one = new Node;
    one->code = "PARAMS 2";
    $$ = one;
}
|  %empty {
    Node* node = new Node;
    $$ = node;

};

var_decl: var_type assignment {

    printf("VAR DECL ");
    Node* one = new Node;
    one = $1;
    Node* ret = new Node;
    ret->code = ". " + $1->code;
    $$ = ret;
};




statements: statement statements {
    printf("STATEMENT 1 ");
    Node* one = new Node;
    one = $1; 
    Node* two = new Node;
    two = $2;
    
    Node* result = new Node();
    result->code = one->code + two->code;
    $$ = result;

}
|  %empty {
    Node* node = new Node;
    $$ = node;

};

statement: var_decl ';' {
    printf("STATEMENT 1 ");
    Node* one = new Node;
    one = $1;
    $$ = one;
}
| func_decl {
   /* Node* one = new Node;
   one = $1;
    $$ = one;*/
}
| cond {
    /*Node* one = new Node;
    one = $1;
    $$ = one;*/
}
| loop {
    /*Node* one = new Node;
    one = $1;
    $$ = one;*/
}
| io ';' {
    /*Node* one = new Node;
    one = $1;
    $$ = one;*/
}
| assignment ';' {
    /*Node* one = new Node;
    one = $1;
    $$ = one;*/
}
| return ';' {
    /*Node* one = new Node;
    one = $1;
    $$ = one;*/
};

values: variable {
    /*Node* one = $1;
    $$ = one;*/
}
| value {
    /*Node* one = $1;
    $$ = one;*/
}
| array {
    /*Node* one = $1;
    $$ = one;*/
}
| variable '[' index { 
}
| variable '(' func_params {

} 
; 


return: RETURN exp {
    /*Node* one = $2;
    Node* ret = new Node();
    ret->code = "ret " + one->code;
    $$ = ret;*/
}
;

var_type: INTEGER {}
| ARRAY var_type arr_len {}
;

assignment: values set_val {
    Node* one = new Node;
    one->code = "REACHED";
    $$ = one;
}
;

arr_len: variable {}
| value {}
;


set_val: '=' exp{}
| %empty {
    Node* node = new Node;
    $$ = node;

};

func_params: exp ',' func_params {}
| exp ')' {}
| ')' {}
;


array: '{' arr_vals '}' {}
| '{' '}' {}
;

arr_vals: values ',' arr_vals {}
| values {}
;

index: values ']' {}
;


io: READ variable {}
| WRITE exp {}
;


as: 
'+' {} 
| '-' {}
;

p: 
'(' exp ')' {}
;

md: 
'*' {}
| '/' {}
;


value: INT {}
;

exp: 
exp as mult {
}
| mult {

}
;

mult: mult md factor {}
| factor {}
;

factor: p {}
| values {}
;


cond: IF '[' conditions ']' '{' statements '}' elseif {}
;

elseif: ELSEIF '[' conditions ']' '{' statements '}' elseif{}
| else{}
;
else: ELSE '{' statements '}' {}
| %empty {
    Node* node = new Node;
    $$ = node;

};

loop: WHILE '[' conditions ']' '{' statements '}' {}
;

condition: condition conditional exp {}
| exp {}
| '(' condition conditional exp ')' {}
;

conditional: '>' {}
| '<' {}
| GTE {}
| LTE {}
| ISEQ {}
| NOTEQ {}
;


conditions: condition {}
| condition AND conditions {}
| condition OR conditions {}
;
%%


int main (int argc, char** argv) {
  yyin = stdin;

  do {
    yyparse();
  } while(!feof(yyin));
  return 0;
}

