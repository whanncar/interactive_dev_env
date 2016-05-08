
#include "replacement_engine.h"
#include <string.h>

void execute_preprocess_replacement(replacement_node *, code_node *);









replacement_node *preprocess_replacements(char *pseudocode_template,
                                          char *pseudocode) {

    int start, end;

    for (start = 0; pseudocode[start] != '\0'; start++) {

        if (pseudocode[start] == '_') {

            for (end = 0; pseudocode[end] != '_'; 

        }

    }

}





void execute_preprocessed_replacement(replacement_node *replacements,
                                    code_node *code_bites) {

    replacement_node *replacement;
    code_node *code_bite;

    /* For each code bite */
    for (code_bite = code_bites;
         code_bite != NULL;
         code_bite = code_bite->next) {
        /* If the code bite should be replaced */
        if (code_bite->token->replace) {
            /* For each possible replacement */
            for (replacement = replacements;
                 replacement != NULL;
                 replacement = replacement->next) {
                /* If the replacement is the correct one */
                if (strcmp(replacement->token->name,
                           code_bite->token->value) == 0) {
                    /* 
                     * Perform the replacement and
                     * move on to the next code bite
                     */
                    code_bite->token->value = replacement->token->value;
                    code_bite->token->replace = 0;
                    break;
                }
            }
        }
    }
}
