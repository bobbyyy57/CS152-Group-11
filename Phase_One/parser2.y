%{
    #include <stdio.h>
    #include "Node.h"
    #include <stdlib.h>
    #include <string.h>
    FILE* yyin;
    extern int row, col;

    void yyerror(const char* msg) {
    }
%}

%union {
    int val;
    char* name;
}

%token 
    INTEGER STRING ARRAY FUNCTION IF ELSE
    WHILE READ WRITE ELSEIF GTE LTE ISEQ NOTEQ
    AND OR RETURN

%token <val> INT
%token <name> VAR

%start start
%define parse.error verbose

%left '+' '-'
%left '*' '/'

%%


statements: statement statements 
| /*empty*/			       
;

statement: var_decl ';' 
| func_decl
| cond 
| loop 
| io ';' 
| assignment ';' 
| return ';' 
;

values: variable 
| value 
| array 
| variable '[' index 
| variable '(' func_params 
; 



start: func_decl 
| /*empty*/ 
;

params: var_decl ',' params {
}
| var_decl {

}
| /*empty*/ 
;

func_decl: var_type FUNCTION variable '[' params ']' '{' statements '}' 
| var_type FUNCTION variable '[' params ']' '{' statements '}' func_decl
;

return: RETURN exp 
;



var_decl: var_type assignment
;

var_type: INTEGER 
| ARRAY var_type arr_len 
;

assignment: values set_val 
;

arr_len: variable 
| value
;


set_val: '=' exp
| /*epsilon*/ 
;

func_params: exp ',' func_params 
| exp ')' 
| ')' 
;


array: '{' arr_vals '}' 
| '{' '}' 
;

arr_vals: values ',' arr_vals 
| values 
;

index: values ']' 
;


io: READ variable 
| WRITE exp 
;


as: 
'+' {

} 
| '-' {

}
;

p: 
'(' exp ')' {

}
;

md: 
'*' {

}
| '/' {
    
}
;

variable: VAR 
;

value: INT 
;

exp: 
exp as mult {
}
| mult {

}
;

mult: mult md factor 
| factor
;

factor: p
| values 
;


cond: IF '[' conditions ']' '{' statements '}' elseif 
;

elseif: ELSEIF '[' conditions ']' '{' statements '}' elseif
| else
;
else: ELSE '{' statements '}' 
| /*empty*/ 
;

loop: WHILE '[' conditions ']' '{' statements '}' 
;

condition: condition conditional exp 
| exp 
| '(' condition conditional exp ')' 
;

conditional: '>' 
| '<' 
| GTE 
| LTE 
| ISEQ 
| NOTEQ 
;


conditions: condition 
| condition AND conditions 
| condition OR conditions 
;









