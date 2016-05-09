#include "replacement_engine.h"
#include <stdlib.h>
#include <stdio.h>

void test1();

int main() {

    test1();

}


void test1() {

    char *pseudocode_template = "add vectors _v1_ and _v2_ of length _l_ together and store result in _v3_";

    char *pseudocode = "add vectors arr1 and arr2 of length 7 together and store result in result";

    char *code = "for (int i = 0; i < l ; i++) {\n"
                 "    v3 [i] = v1 [i] + v2 [i];\n"
                 "}";

    char *result = execute_replacement(pseudocode_template, pseudocode, code);

    printf("\n%s\n\n", result);
}

void test2() {

    char *pseudocode_template = "make like mingus with _x_";

    char *pseudocode = "make like mingus with banana";

    char *code = "x x x x x;";

    char *result = execute_replacement(pseudocode_template, pseudocode, code);

    printf("\n%s\n\n", result);

}
