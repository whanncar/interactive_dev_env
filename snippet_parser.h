/*
 * Need to add description here UNRESOLVED 
 *
 */


typedef struct snippet_struct {

    char *pseudocode;
/* removed for testing UNRESOLVED    char **description; */
    char *code; 

} snippet;


typedef struct tag_linked_list {

    char *name;

    char *start_tag;
    char *end_tag;

    int start_tag_length;
    int end_tag_length;

    struct tag_linked_list *next;

} tag_list;



/* Public methods */

snippet *parse_snippet(char *, tag_list *);
void free_snippet(snippet *);
void print_snippet(snippet *, tag_list *);
