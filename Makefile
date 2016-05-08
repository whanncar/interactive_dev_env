

all: snippet_parser_test

snippet_parser_test: snippet_parser.o snippet_parser.h snippet_parser_test.o
	gcc snippet_parser_test.o snippet_parser.o -o snippet_parser_test

snippet_parser.o: snippet_parser.c snippet_parser.h
	gcc -c snippet_parser.c

snippet_parser_test.o: snippet_parser.h snippet_parser.o snippet_parser_test.c
	gcc -c snippet_parser_test.c

clean:
	rm -f *.o snippet_parser_test
