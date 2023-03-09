all:
	bison -v -d --file-prefix=y parser_test.y
	flex lexer.lex
	g++ -o parser y.tab.c lex.yy.c -lfl
