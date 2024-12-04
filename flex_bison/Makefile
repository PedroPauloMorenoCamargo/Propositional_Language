all:
	bison -t -d -v parser.y
	flex lexer.l
	gcc parser.tab.c lex.yy.c -o parser -lfl