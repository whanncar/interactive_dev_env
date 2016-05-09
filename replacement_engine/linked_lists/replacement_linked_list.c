

void set_replacement_token_value(replacement_token *token, char *new_value) {

    /* Free the old value */
    free(token->value);
    /* Store the new value */
    token->value = new_value; 

}


replacement_token_list *new_replacement_token_list() {

    replacement_token_list *new_list;

    /* Allocate space for a new list */
    new_list = (replacement_token_list *) malloc(sizeof(replacement_token_list));
    /* Set all fields to NULL */
    new_list->first = NULL;
    new_list->last = NULL;

    return new_list;

}


replacement_token_node *new_replacement_token_node() {

    replacement_token_node *new_node;

    new_node = (replacement_token_node *) malloc(sizeof(replacement_token_node));

    new_node->token = new_replacement_token();;
    new_node->next = NULL;

    return new_node;

}


replacement_token *new_replacement_token() {

    replacement_token *new_token;

    new_token = (replacement_token *) malloc(sizeof(replacement_token));

    new_token->name = NULL;
    new_token->value = NULL;

    return new_token;

}



void add_replacement_pair_to_list(replacement_token_list *list, char *name, char *value) {

    replacement_token_node *new_node;

    /* Initialize new node */
    new_node = new_replacement_token_node();
    /* Initi the new node's name and value */
    new_node->token->name = name;
    new_node->token->value = value;

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
