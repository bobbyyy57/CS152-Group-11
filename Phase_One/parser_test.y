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

    bool assDecl = false;
    bool assAddSub = false;
    bool assMulDiv = false;

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

        Node* one = $5;
        res->code += $5->code;
        res->code += $8->code;
        res->code += "endfunc";
        $$ = res;
}
| var_type FUNCTION variable '[' params ']' '{' statements '}' func_decl {
}
;

variable: VAR {
    $$ = new Node();
    $$->name = $1;
};

params: variable ',' params {
    Node* res = new Node;
    Node* res2 = new Node;
    res->code += "param " + $1->name + " \n";
    res2->code += $3->code;
    
    $$->code = res->code + res2->code;
}
| variable {
    Node* res = new Node;
    res->code += "param " + $1->name + " \n";
    $$ = res;
}
|  %empty {
    Node* node = new Node;
    $$ = node;

};

var_decl: var_type assignment {
    Node* one = $2;
    Node* ret = new Node;
    ret->code += ". " + $2->code + " \n";
    $$ = ret;
} 
| var_type variable {
    Node* ret = new Node;
    ret->code += ". " + $2->code + " \n";
    $$ = ret;
};

assignment: values set_val {
    Node* res = new Node;
    res->code += "= " + $1->name + ", " + $2->name + " \n";
    $$ = res;
}
;
set_val: '=' exp {
    Node* ret = new Node;
    ret->code = $2->code;
    $$ = ret;
}
| %empty {
    Node* node = new Node;
    $$ = node;
};


as: 
'+' {
    $$ = new Node;
    $$->code = "+";
} 
| '-' {
    $$ = new Node;
    $$->code = "-";
}
;

p: 
'(' exp ')' {
    $$ = new Node;
    $$->code = $2->code;
}
;

md: 
'*' {
    $$ = new Node;
    $$->code = "*";
}
| '/' {
    $$ = new Node;
    $$->code = "/";
}
;


value: INT {
    $$ = new Node;
    $$->name = $1;
}
;

exp: exp as mult {
    Node* res = new Node;
    res->code += $1->code + ", " + $3->code;
    $$ = res;
}
| mult {
    $$ = new Node;
    $$->code = $1->code;
}
;

mult: mult md factor {
    Node* res = new Node;
    res->code += $1->code + ", " + $3->code;
    $$ = res;
}
| factor {
    $$ = new Node;
    $$->code = $1->code;
}
;

factor: p {}
| values {
    $$ = new Node;
    $$->code = $1->code;

}
;

values: variable {
    Node* one = $1;
    $$ = one;
}
| value {
    Node* one = $1;
    $$ = one;
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





statements: statement statements {
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


arr_len: variable {}
| value {}
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

