all:
	flex lexer.lex
	bison -v -d --file-prefix=y parser.y
	gcc -o parser y.tab.c lex.yy.c -lfl
