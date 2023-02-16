%{
    #include <stdio.h>
    FILE* yyin;
    extern int row, col;

    void yyerror(const char* msg) {
        printf("ERROR: Row %d, Col %d, %s\n", row, col, msg);
    }
%}

// We don't have or?
// Also specify array initialization/indexing
// Also need string? Or remove them
// Naming functions
// Calling functions
// Multiple conditions
// Add else_if
// Change/Add logical operators
// Change/Add boolean operators

%union {
    int val;
    char* name;
}

%token 
    INTEGER STRING ARRAY FUNCTION IF ELSE
    WHILE READ WRITE

%token <val> INT
%token <name> VAR

%start start

%left '+' '-'
%left '*' '/'

%%
start: statements {printf("start -> statements\n");}
;

statements: statement statements {printf("statements -> statement statements\n");}
| /*empty*/			       {printf("statements -> epsilon\n");}
;

statement: var_decl ';' {printf("statement -> var_decl ;\n");}
| func_decl {printf("statement -> func_decl\n");}
| cond {printf("statement -> cond\n");}
| loop {printf("statement -> loop\n");}
| io ';' {printf("statement -> io ;\n");}
| assignment ';' {printf("statement -> assignment ;\n");} 
;



var_type: INTEGER {printf("var_type -> INTEGER\n");}
| ARRAY var_type arr_len {printf("var_type -> ARRAY var_type arr_len");}
;

arr_len: variable {printf("arr_len -> variable\n");}
| value {printf("arr_len -> value\n");}

var_decl: var_type assignment {printf("var_decl -> var_type assignment\n");}
;

assignment: variable set_val {printf("assignment -> variable set_val\n");}
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



func_decl: values FUNCTION variable '[' params ']' '{' statements '}' {printf("func_decl -> values FUNCTION variable [params] {statements}\n");}
;

params: var_decl ',' params {printf("params -> var_decl, params\n");}
| var_decl {printf("params -> var_decl\n");}
| /*empty*/ {printf("params -> epsilon\n");}
;



cond: IF '[' conditions ']' '{' statements '}' {printf("cond -> IF [conditions] {statements}\n");}
| ELSE '{' statements '}' {printf("cond -> ELSE {statements}\n");}
; 

loop: WHILE '[' conditions ']' '{' statements '}' {printf("loop -> WHILE [conditions] {statements}\n");}
;

conditions: condition {printf("conditions -> condition\n");}
;

condition: /*empty*/ {printf("TODO Add logical operators!\n");}
;

io: READ variable {printf("io -> READ variable\n");}
| WRITE values {printf("io -> WRITE values\n");}
;



values: variable {printf("values -> variable\n");}
| value {printf("values -> value\n");}
| array {printf("values -> array\n");}
; // Add strings if we are keeping strings
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

