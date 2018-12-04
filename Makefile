parser: y.tab.c lex.yy.c y.tab.h
				gcc y.tab.c lex.yy.c -ll -ly -o parser

lex.yy.c: parser.l
				lex parser.l

y.tab.c: parser.y
				yacc -v -d parser.y
clean:
				rm -f y.tab.c lex.yy.c y.tab.h parser y.output
