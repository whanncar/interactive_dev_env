

typedef struct replacement_token {

    char *name;
    char *value;

} replacement_token;

/*

typedef struct code_token {

    char *value;
    char replace;

} code_token;

*/

typedef struct replacement_token_linked_list_node {

    replacement_token *token;

    struct replacement_token_linked_list_node *next;

} replacement_node;


/*
typedef struct code_token_linked_list_node {

    code_token *token;

    struct code_token_linked_list_node *next;

} code_node;
*/


typedef struct string_token_linked_list_node {

    char *token;

    struct string_token_linked_list_node *next;

} string_token_node;
