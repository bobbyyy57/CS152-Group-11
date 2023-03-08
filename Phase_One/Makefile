all:
	flex lexer.lex
	bison -v -d --file-prefix=y parser_test.y
	g++ -o parser y.tab.c lex.yy.c -lfl
