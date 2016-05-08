
#include "replacement_engine.h"
#include <string.h>

void execute_preprocess_replacement(replacement_node *, code_node *);
string_token_node *tokenize(char *);








replacement_node *preprocess_replacements(char *pseudocode_template,
                                          char *pseudocode) {

    replacement_node *replacement_list = NULL;
    replacement_node *current_replacement_node = NULL;
    replacement_node *new_replacement_node = NULL;
    string_token_node *p_t_token_list;
    string_token_node *p_token_list;

    /* Tokenize the template and the instruction */
    p_t_token_list = tokenize(pseudocode_template);
    p_token_list = tokenize(pseudocode);

    /* For each token */
    for (; p_t_token_list != NULL; 
         p_t_token_list = p_t_token_list->next,
         p_token_list = p_token_list->next) {
        /* If the token is a token to replace */
        if (p_t_token_list->token[0] == '_') {

            if (replacement_list == NULL) {

                replacement_list =
                    (replacement_node *) malloc(sizeof(replacement_node));
                current_replacement_node = replacement_list;
                new_replacement_node = replacement_list;
                
            }

            else {
                new_replacement_node =
                    (replacement_node *) malloc(sizeof(replacement_node));
            }

            current_replacement_node->next = new_replacement_node;
            new_replacement_node->next = NULL;

            new_replacement_node->token = 
                    (replacement_token *) malloc(sizeof(replacement_token));
            
            new_replacement_node->token

        }

    }

}


string_token_node *tokenize(char *s) {

    int i, j;
    int length;
    string_token_node *tokens = NULL;
    string_token_node *current_token = NULL;
    string_token_node *new_token = NULL;

    length = 0;

    /* For each character in s */
    for(i = 0; s[i] != '\0'; i++) {
        /* If the character is a space */
        if (s[i] == ' ') {
            /* 
             * If the character was preceded by a space,
             * move on to next character
             */
            if (length == 0) {
                continue;
            }
            /* If this is the first token */
            if (tokens == NULL) {
                /* Initialize so that everything will work */
                tokens = (string_token_node *) malloc(sizeof(string_token_node));
                current_token = tokens;
                new_token = tokens;
            }
            /* Otherwise */
            else {
                /* Allocate space for the new token node */
                new_token = (string_token_node *) malloc(sizeof(string_token_node));
            }
            /* Allocate space for the new token node's token */
            new_token->token = (char *) malloc((length + 1) * sizeof(char));
            /* Add the new token node to the linked list */
            current_token->next = new_token;
            new_token->next = NULL;
            /* Copy the token into the new token node */
            for (j = 0; j < length; j++) {
                (new_token->token)[j] = s[i - length + j];
            }
            /* Add end of string character */
            (new_token->token)[length] = '\0';
            /* Get ready for the next token */
            length = 0;
            current_token = new_token;
        }
        /* If the character is not a space, increment length */
        else {
            length++;
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
