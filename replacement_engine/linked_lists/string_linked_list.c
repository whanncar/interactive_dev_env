

void set_string_token_value(string_token_node *node, char *new_value) {

    int len, i;

    /* Free the old value */
    free(node->value);
    /* Store the new value */
    node->value = new_value; 

}


string_token_list *new_string_token_list() {

    string_token_list *new_list;

    /* Allocate space for a new list */
    new_list = (string_token_list *) malloc(sizeof(string_token_list));
    /* Set all fields to NULL */
    new_list->first = NULL;
    new_list->last = NULL;

    return new_list;

}


string_token_node *new_string_token_node() {

    string_token_node *new_node;

    new_node = (string_token_node *) malloc(sizeof(string_token_node));

    new_node->value = NULL;
    new_node->next = NULL;

    return new_node;

}

void add_string_token_to_list(string_token_list *list, char *s) {

    int len, i;
    string_token_node *new_node;

    /* Calculate the length of the string */
    len = string_length(s);

    /* Initialize new node */
    new_node = new_string_token_node();
    /* Store the new node's value */
    new_node->value = s;

    /* If the list is empty, make new node the only node in the list */
    if (list->first == NULL) {
        list->first = new_node;
        list->last = new_node;
    }
    /* Otherwise, add new node to the list */
    else {
        list->last->next = new_node;
        list->last = new_node;
    }
}
