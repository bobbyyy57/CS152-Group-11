all:
	bison -v -d --file-prefix=y parser_temp.y
	flex lexer.lex
	g++ -std=c++11 -o parser y.tab.c lex.yy.c -lfl
