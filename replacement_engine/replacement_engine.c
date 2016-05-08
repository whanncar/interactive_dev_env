#include <stdlib.h>
#include <stdio.h>
#include "replacement_engine.h"
#include <string.h>

void execute_preprocess_replacement(replacement_node *, string_token_node *);
string_token_node *tokenize(char *);
int string_length(char *);
replacement_node *preprocess_replacements(char *, char *);
char *detokenize(string_token_node *);

char *execute_replacement(char *pseudocode_template, char *pseudocode, char *code) {

    replacement_node *replacements;
    string_token_node *tokenized_code;
    char *new_code;

    /* Prepare the replacements */
    replacements = preprocess_replacements(pseudocode_template, pseudocode);
    /* Tokenize the code */
    tokenized_code = tokenize(code);
    /* Perform the replacements */
    execute_preprocess_replacement(replacements, tokenized_code);
    /* Detokenize the code */
    new_code = detokenize(tokenized_code);

    /* Eventually going to have to free stuff here UNRESOLVED */

    return new_code;

}


/* Prepares the replacement list from the template and the raw instruction */
replacement_node *preprocess_replacements(char *pseudocode_template,
                                          char *pseudocode) {

    int i, len;
    replacement_node *replacement_list = NULL;
    replacement_node *current_replacement_node = NULL;
    replacement_node *new_replacement_node = NULL;
    string_token_node *p_t_token_list;
    string_token_node *p_token_list;

    string_token_node *temp;

    /* Tokenize the template and the instruction */
    p_t_token_list = tokenize(pseudocode_template);
    p_token_list = tokenize(pseudocode);

    /* For each token */
    for (; p_t_token_list != NULL; 
         p_t_token_list = p_t_token_list->next,
         p_token_list = p_token_list->next) {
        /* If the token is a token to replace */
        if (p_t_token_list->token[0] == '_') {
            /* If this is the first replacement token */
            if (replacement_list == NULL) {
                /* Initialize so that everything will work */
                replacement_list =
                    (replacement_node *) malloc(sizeof(replacement_node));
                current_replacement_node = replacement_list;
                new_replacement_node = replacement_list;
            }
            /* Otherwise */
            else {
                /* Allocate space for the new replacement token node */
                new_replacement_node =
                    (replacement_node *) malloc(sizeof(replacement_node));
            }
            /* Add the new replacement token node to the linked list */
            current_replacement_node->next = new_replacement_node;
            new_replacement_node->next = NULL;

            /* Allocate space for the new replacement token */
            new_replacement_node->token = 
                    (replacement_token *) malloc(sizeof(replacement_token));
            /* Calculate the length of the name */
            len = string_length(p_t_token_list->token);
            /* Allocate space for the name in the replacement token */
            new_replacement_node->token->name =
                (char *) malloc((len - 1) * sizeof(char));
            /* Copy the name into the replacement token */
            for (i = 0; i < len - 2; i++) {
                (new_replacement_node->token->name)[i] =
                    (p_t_token_list->token)[i + 1];
            }
            (new_replacement_node->token->name)[len - 2] = '\0';

            /* Calculate the length of the value */
            len = string_length(p_token_list->token);
            /* Allocate space for the value in the replacement token */
            new_replacement_node->token->value =
                (char *) malloc((len + 1) * sizeof(char));
            /* Copy the value into the replacement token */
            for (i = 0; i < len + 1; i++) {
                (new_replacement_node->token->value)[i] = (p_token_list->token)[i];
            }

            /* Get ready for the next replacement token */
            current_replacement_node = new_replacement_node;
        }
    }

    return replacement_list;
}


int string_length(char *s) {

    int i;

    for (i = 0; s[i] != '\0'; i++);

    return i;

}




string_token_node *tokenize(char *s) {

    int i, j;
    int length;
    int newline;
    string_token_node *tokens = NULL;
    string_token_node *current_token = NULL;
    string_token_node *new_token = NULL;

    length = 0;

    /* For each character in s */
    for(i = 0; i == 0 || s[i - 1] != '\0'; i++) {
        /* If the character is a space or a return or the end of the string */
        if (s[i] == ' ' || s[i] == '\n' || s[i] == '\0') {
            /* If this character is a return, increment length */
            if (s[i] == '\n') {
                length++;
                i++;
                newline = 1;
            }
            else {
                newline = 0;
            }
            /* 
             * If this character is a space and was preceded
             * by a space, move on to next character
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
            if (newline) {
                i--;
            }
            current_token = new_token;
        }
        /* If the character is not a space, increment length */
        else {
            length++;
        }
    }

    return tokens;

}



char *detokenize(string_token_node *tokenized_code) {

    int total_len, len, i, j;
    string_token_node *current_token;
    char *detokenized_code;

    /* Set total length to 0 */
    total_len = 0;

    /* Add the length of each token to length */
    for (current_token = tokenized_code;
         current_token != NULL;
         current_token = current_token->next) {
        /* Calculate the length of the token */
        len = string_length(current_token->token);
        /* If the token does not end with a return */
        if ((current_token->token)[len - 1] != '\n') {
            /* Add a space at the end */
            current_token->token = realloc(current_token->token, (len + 2) * sizeof(char)); 
            len++;
            (current_token->token)[len-1] = ' ';
            (current_token->token)[len] = '\0';
        }
        /* Add length to total length */
        total_len += len;
    }

    /* Allocate space for the newly detokenized code */
    detokenized_code = (char *) malloc((total_len + 1) * sizeof(char));

    /* Start i at 0 */
    i = 0;

    for (current_token = tokenized_code;
         current_token != NULL;
         current_token = current_token->next) {
        /* Copy the token into the string */
        len = string_length(current_token->token);
        for (j = 0; j < len; i++, j++) {
            detokenized_code[i] = (current_token->token)[j];
        }
    }

    detokenized_code[total_len] = '\0';

    return detokenized_code;

}





/* Replaced anything that should be replaced in the tokenized code */
void execute_preprocess_replacement(replacement_node *replacements,
                                    string_token_node *tokenized_code) {
    int i, len;
    replacement_node *replacement;
    string_token_node *current_code_token;

    /* For each code token */
    for (current_code_token = tokenized_code;
         current_code_token != NULL;
         current_code_token = current_code_token->next) {
        /* For each possible replacement */
        for (replacement = replacements; 
             replacement != NULL;
             replacement = replacement->next) {
            /* If this is an appropriate replacement */
            if (strcmp(replacement->token->name,
                       current_code_token->token) == 0) {

                /* Calculate the length of the replacement value */
                len = string_length(replacement->token->value);
                /* Free the current code token node's old token */
                free(current_code_token->token);
                /* Allocate space for the current code token node's new token */
                current_code_token->token = (char *) malloc((len + 1) * sizeof(char));
                /* Copy the replacement value into the current code token */
                for (i = 0; i < len + 1; i++) {
                    (current_code_token->token)[i] = (replacement->token->value)[i];
                }

                /* Continue to the next code token */
                break;
            }
            /* Otherwise */
            else {
                /* Calculate the current code token's length */
                len = string_length(current_code_token->token);
                /* If the current code token ends in a return */
                if ((current_code_token->token)[len - 1] == '\n') {
                    /* Replace the return with an end of string character */
                    (current_code_token->token)[len - 1] = '\0';
                    /* If this is now an appropriate replacement */
                    if (strcmp(replacement->token->name,
                               current_code_token->token) == 0) {

                        /* Calculate the length of the replacement value */
                        len = string_length(replacement->token->value);
                        /* Free the current code token node's old token */
                        free(current_code_token->token);
                        /* Allocate space for the current code token node's new token */
                        current_code_token->token = (char *) malloc((len + 2) * sizeof(char));
                        /* Copy the replacement value into the current code token with a return */
                        for (i = 0; i < len; i++) {
                            (current_code_token->token)[i] = (replacement->token->value)[i];
                        }
                        (current_code_token->token)[len] = '\n';
                        (current_code_token->token)[len + 1] = '\0';

                        /* Continue to the next code token */
                        break;
                    }
                    /* Otherwise */
                    else {
                        /* Put the return back */
                        (current_code_token->token)[len - 1] = '\n';
                    }
                }
            }
        }
    }
}
