

typedef struct replacement_token {

    char *name;
    char *value;

} replacement_token;



typedef struct replacement_token_linked_list_node {

    replacement_token *token;

    struct replacement_token_linked_list_node *next;

} replacement_node;


typedef replacement_token_linked_list {

    replacement_node *first;
    replacement_node *last;

} replacement_token_list;




typedef struct string_token_linked_list_node {

    char *token;

    struct string_token_linked_list_node *next;

} string_token_node;


/*

typedef struct string_token_linked_list_node {

    char *value;

    struct string_token_linked_list_node *next;

} string_token_node;

*/


typedef struct string_token_linked_list {

    string_token_node *first;
    string_token_node *last;

} string_token_list;





char *execute_replacement(char *, char *, char *);
