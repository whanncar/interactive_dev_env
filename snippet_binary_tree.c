/*
 * Need to do all kinds of commenting UNRESOLVED
 *
 */

#include "snippet_parser.h"
#include "snippet_binary_tree.h"

int compare_strings(char *, char *);
void add_child_snippet(snippet_tree_node *, snippet *);
snippet_tree_node *make_new_node(snippet *);





void add_snippet_to_tree(snippet_tree *tree, snippet *new_snippet){

    /* IF tree is nonempty, send new snippet to root */
    if (tree->root != NULL) {
        add_child_snippet(tree->root, new_snippet);
    }
    /* Otherwise, store new snippet as the root */
    else{
        tree->root = make_new_node(new_snippet);
    }

}



void add_child_snippet(snippet_tree_node *node, snippet *new_snippet) {

    /* Get comparison value */
    int compare = compare_strings(node->value->pseudocode,
                                  new_snippet->pseudocode);

    /* 
     * If pseudocode string of new snippet is less than pseudocode string
     * of this snippet, store the new snippet to the left
     */
    if (compare < 0) {
        if (node->left != NULL) {
            add_child_snippet(node->left, new_snippet);
        }
        else {
            node->left = make_new_node(new_snippet);
        }
    }

    /*
     * If pseudocode string of new snippet is greater than pseudocode string
     * of this snippet, store the new snippet to the right
     */
    if (compare > 0) {
        if (node->right != NULL) {
            add_child_snippet(node->right, new_snippet);
        }
        else{
            node->right = make_new_node(new_snippet);
        }
    }

}



snippet_tree_node *make_new_node(snippet *s) {

    snippet_tree_node *new_node =
                    (snippet_tree_node *) malloc(sizeof(snippet_tree_node));

    new_node->left = NULL;
    new_node->right = NULL;
    new_node->value = s;

    return new_node;

}



/* This should eventually live somewhere else UNRESOLVED */

/* Returns -1 if a < b, 0 of a == b, and 1 if a > b */

int compare_strings(char *a, char *b) {

    int i;

    for (i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
        if (a[i] < b[i]) {
            return -1;
        }
        if (a[i] > b[i]) {
            return 1;
        }
    }

    if (a[i] == '\0' && b[i] == '\0') {
        return 0;
    }
    else if (a[i] == '\0') {
        return -1;
    }
    else {
        return 1;
    }

}
