%{
    extern int yyparse();
    extern int yylex();
   
    #include <stdio.h>
    #include "Node.h"
    
    extern FILE* yyin;
    extern int row, col;

    void yyerror(const char* msg) {
        printf("ERROR: Row %d, Col %d, %s\n", row, col, msg);
    }

    /*struct CodeNode {
      char* code;
      char* name;
    };*/

    bool MULOP = false;

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
    Node* node = $1;
    printf("s\n", node->code.c_str());
}
| /*empty*/ {
};

statements: statement statements {
    Node* one = $1; 
    Node* two = $2;
    
    Node* result = new Node();
    result->code = one->code + two->code;
    $$ = result;
}
| /*empty*/	{
    Node* empt = new Node();
    $$ = empt;
};

statement: var_decl ';' {
    Node* one = $1;
    $$ = one;
}
| func_decl {
    Node* one = $1;
    $$ = one;
}
| cond {
    Node* one = $1;
    $$ = one;
}
| loop {
    Node* one = $1;
    $$ = one;
}
| io ';' {
    Node* one = $1;
    $$ = one;
}
| assignment ';' {
    Node* one = $1;
    $$ = one;
}
| return ';' {
    Node* one = $1;
    $$ = one;
};

var_decl: var_type assignment {
    Node* one = $1;
    Node* ret;
    ret->code = ". " + $1->code;
    $$ = ret;
};

values: variable {
    Node* one = $1;
    $$ = one;
}
| value {
    Node* one = $1;
    $$ = one;
}
| array {
    Node* one = $1;
    $$ = one;
}
| variable '[' index {}
| variable '(' func_params {} 
; 


params: var_decl ',' params {}
| var_decl {}
| /*empty*/ {};

func_decl: var_type FUNCTION variable '[' params ']' '{' statements '}' 
| var_type FUNCTION variable '[' params ']' '{' statements '}' func_decl
;

return: RETURN exp {
    Node* one = $2;
    Node* ret = new Node();
    ret->code = "ret " + one->code;
    $$ = ret;
}
;

var_type: INTEGER {}
| ARRAY var_type arr_len {}
;

assignment: values set_val {

}
;

arr_len: variable {}
| value {}
;


set_val: '=' exp{}
| /*epsilon*/ {}
;

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
'+' {
    Node* one = $1;
    $$ = one;
} 
| '-' {}
;

p: 
'(' exp ')' {}
;

md: 
'*' {}
| '/' {}
;

variable: VAR {}
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
| /*empty*/ {}
;

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

