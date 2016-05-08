#include "replacement_engine.h"
#include <stdlib.h>
#include <stdio.h>


int main() {

    char *pseudocode_template = "add vectors _v1_ and _v2_ of length _l_ together and store result in _v3_";

    char *pseudocode = "add vectors arr1 and arr2 of length 7 together and store result in result";

    char *code = "for (int i = 0; i < l ; i++) {"
                 "    v3 [i] = v1 [i] + v2 [i];"
                 "}";

    char *result = execute_replacement(pseudocode_template, pseudocode, code);

    printf("\n%s\n\n", result);

}
