

all: snippet_parser_test replacement_engine_test tidy

snippet_parser_test: snippet_parser.o ./snippet/snippet_parser.h snippet_parser_test.o
	gcc snippet_parser_test.o snippet_parser.o -o snippet_parser_test

snippet_parser.o: ./snippet/snippet_parser.c ./snippet/snippet_parser.h
	gcc -c ./snippet/snippet_parser.c

snippet_parser_test.o: ./snippet/snippet_parser.h snippet_parser.o ./snippet/snippet_parser_test.c
	gcc -c ./snippet/snippet_parser_test.c

replacement_engine.o: ./replacement_engine/replacement_engine.c ./replacement_engine/replacement_engine.h
	gcc -c ./replacement_engine/replacement_engine.c

replacement_engine_test.o: ./replacement_engine/replacement_engine_test.c ./replacement_engine/replacement_engine.h
	gcc -c ./replacement_engine/replacement_engine_test.c

replacement_engine_test: replacement_engine_test.o replacement_engine.o
	gcc replacement_engine_test.o replacement_engine.o -o replacement_engine_test

tidy:
	rm -f *.o

clean: tidy
	rm -f snippet_parser_test replacement_engine_test
