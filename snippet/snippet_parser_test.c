#include <stdlib.h>
#include <stdio.h>
#include "snippet_parser.h"

tag_list *make_tag_list(void);

int main(void) {

    char *test_snippet = "<pseudocode>\n"
                         "store _a_ + _b_ in _c_\n"
                         "</pseudocode>\n"
                         "<code>\n"
                         "c = a + b;\n"
                         "</code>\n";

    tag_list *list = make_tag_list();

    snippet *parsed_snippet = parse_snippet(test_snippet, list);

    print_snippet(parsed_snippet, list);

    free_snippet(parsed_snippet);

}



tag_list *make_tag_list() {

    tag_list *pseudo;
    tag_list *cod;

    /* Make pseudocode tag */
    pseudo = (tag_list *) malloc(sizeof(tag_list));

    pseudo->name = "Pseudocode";

    pseudo->start_tag_length = 12;
    pseudo->end_tag_length = 13;

    pseudo->start_tag = (char *) malloc((pseudo->start_tag_length + 1) * sizeof(char));
    pseudo->end_tag = (char *) malloc((pseudo->end_tag_length + 1) * sizeof(char));

    pseudo->start_tag = "<pseudocode>";
    pseudo->end_tag = "</pseudocode>";

    /* Make code tag */
    cod = (tag_list *) malloc(sizeof(tag_list));

    cod->name = "Code";

    cod->start_tag_length = 6;
    cod->end_tag_length = 7;

    cod->start_tag = (char *) malloc((cod->start_tag_length + 1) * sizeof(char));
    cod->end_tag = (char *) malloc((cod->end_tag_length + 1) * sizeof(char));

    cod->start_tag = "<code>";
    cod->end_tag = "</code>";


    /* Assemble the list */
    pseudo->next = cod;
    cod->next = NULL;

    return pseudo;

}
