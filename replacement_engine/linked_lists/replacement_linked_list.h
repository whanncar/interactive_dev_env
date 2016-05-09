
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


