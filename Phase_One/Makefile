all:
	bison -v -d --file-prefix=y parser4.y
	flex lexer.lex
	g++ -std=c++11 -o parser y.tab.c lex.yy.c -lfl
