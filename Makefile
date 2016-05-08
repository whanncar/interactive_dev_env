

all: snippet_parser_test

snippet_parser_test: snippet_parser.o snippet_parser.h snippet_parser_test.o
	gcc snippet_parser_test.o snippet_parser.o -o snippet_parser_test

snippet_parser.o: snippet_parser.c snippet_parser.h
	gcc -c snippet_parser.c

snippet_parser_test.o: snippet_parser.h snippet_parser.o snippet_parser_test.c
	gcc -c snippet_parser_test.c

replacement_engine.o: replacement_engine.c replacement_engine.h
	gcc -c replacement_engine.c

replacement_engine_test.o: replacement_engine_test.c replacement_engine.h
	gcc -c replacement_engine_test.c

replacement_engine_test: replacement_engine_test.o replacement_engine.o
	gcc replacement_engine_test.o replacement_engine.o -o replacement_engine_test

clean:
	rm -f *.o snippet_parser_test replacement_engine_test
