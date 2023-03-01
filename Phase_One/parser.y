%{
    #include <stdio.h>
    FILE* yyin;
    extern int row, col;

    void yyerror(const char* msg) {
        printf("ERROR: Row %d, Col %d, %s\n", row, col, msg);
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
start: func_decl {printf("start -> statements\n");}
| /*empty*/ {printf("start -> epsilon\n");}
;

statements: statement statements {printf("statements -> statement statements\n");}
| /*empty*/			       {printf("statements -> epsilon\n");}
;

statement: var_decl ';' {printf("statement -> var_decl ;\n");}
//| func_decl {printf("statement -> func_decl\n");}
| cond {printf("statement -> cond\n");}
| loop {printf("statement -> loop\n");}
| io ';' {printf("statement -> io ;\n");}
| assignment ';' {printf("statement -> assignment ;\n");} 
| return ';' {printf("statement -> return ;\n");}
;



var_type: INTEGER {printf("var_type -> INTEGER\n");}
| ARRAY var_type arr_len {printf("var_type -> ARRAY var_type arr_len");}
;

arr_len: variable {printf("arr_len -> variable\n");}
| value {printf("arr_len -> value\n");}

var_decl: var_type assignment {printf("var_decl -> var_type assignment\n");}
;


assignment: values set_val {printf("assignment -> values set_val\n");}
;

set_val: '=' exp {printf("set_val -> = exp\n");}
| /*epsilon*/ {printf("set_val -> epsilon\n");}
;

exp: exp as mult {printf("exp -> exp as mult\n");}
| mult {printf("exp -> mult\n");}
;

mult: mult md factor {printf("mult -> mult md factor\n");}
| factor {printf("mult -> factor\n");}
;

factor: p {printf("factor -> p\n");}
| values {printf("factor -> values\n");}
;



func_decl: var_type FUNCTION variable '[' params ']' '{' statements '}' {printf("func_decl -> var_type FUNCTION variable [params] {statements}\n");}
| var_type FUNCTION variable '[' params ']' '{' statements '}' func_decl
;

params: var_decl ',' params {printf("params -> var_decl, params\n");}
| var_decl {printf("params -> var_decl\n");}
| /*empty*/ {printf("params -> epsilon\n");}
;



cond: IF '[' conditions ']' '{' statements '}' elseif {printf("cond -> IF [conditions] {statements} elseif\n");}
;

elseif: ELSEIF '[' conditions ']' '{' statements '}' elseif {printf("elseif -> ELSEIF [conditions] {statements} elseif\n");}
| else {printf("elseif -> else\n");}
;
else: ELSE '{' statements '}' {printf("else -> ELSE {statements}\n");}
| /*empty*/ {printf("else -> epsilon\n");}
; 

loop: WHILE '[' conditions ']' '{' statements '}' {printf("loop -> WHILE [conditions] {statements}\n");}
;

conditions: condition {printf("conditions -> condition\n");}
| condition AND conditions {printf("conditions -> condition AND conditions\n");}
| condition OR conditions {printf("conditions -> condition OR conditions\n");}
;

condition: condition conditional exp {printf("condition -> condition conditiional exp\n");}
| exp {printf("condition -> exp\n");}
| '(' condition conditional exp ')' {printf("condition -> (condition conditional exp)\n");} 
;

conditional: '>' {printf("conditional -> >\n");}
| '<' {printf("conditional -> <\n");}
| GTE {printf("conditional -> GTE\n");}
| LTE {printf("conditional -> LTE\n");}
| ISEQ {printf("conditional -> ISEQ\n");}
| NOTEQ {printf("conditional -> NOTEQ\n");}
;

io: READ variable {printf("io -> READ variable\n");}
| WRITE exp {printf("io -> WRITE exp\n");}
;



return: RETURN exp {printf("return -> RETURN exp\n");}
;



values: variable {printf("values -> variable\n");}
| value {printf("values -> value\n");}
| array {printf("values -> array\n");}
| variable '[' index {printf("values -> '[' index\n");}
| variable '(' func_params {printf("values -> '(' func_params\n");}
; 
func_params: exp ',' func_params {printf("func_params: exp, func_params\n");}
| exp ')' {printf("func_params -> exp)\n");}
| ')' {printf("func_params -> ')'\n");} 
;
p: '(' exp ')' {printf("p -> (exp)\n");}
;
md: '*' {printf("md -> *\n");}
|'/' {printf("md -> /\n");}
;
as: '+' {printf("as -> +\n");}
| '-' {printf("as -> -\n");}
;
variable: VAR {printf("variable -> VAR %s\n", yylval.name);}
;
index: values ']' {printf("index -> values ]\n");}
;
value: INT {printf("value -> INT %d\n", yylval.val);}
;
array: '{' arr_vals '}' {printf("array -> {arr_vals}\n");}
| '{' '}' {printf("array -> {}\n");}
;
arr_vals: values ',' arr_vals {printf("arr_vals -> values, arr_vals\n");}
| values {printf("arr_vals -> values\n");}
;
%%

int main(int argc, char *argv[]) {
    if (argv > 1) yyin = fopen(argv[1], "r");
    else yyin = stdin;

    yyparse();
    return 0;
}

