
typedef struct string_token_linked_list_node {

    char *value;

    struct string_token_linked_list_node *next;

} string_token_node;



typedef struct string_token_linked_list {

    string_token_node *first;
    string_token_node *last;

} string_token_list;




string_token_list *new_string_token_list();
void add_string_token_to_list(string_token_list *, char *);
