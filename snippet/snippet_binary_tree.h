
#include "snippet_parser.h"

typedef struct snippet_binary_tree_node {

    snippet *value;

    struct snippet_binary_tree *left;
    struct snippet_binary_tree *right;

} snippet_tree_node;



typedef struct snippet_binary_tree {

    snippet_tree_node *root;

} snippet_tree;



void add_snippet_to_tree(snippet_tree *, snippet *);

