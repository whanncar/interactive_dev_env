#include <stdlib.h>
#include <stdio.h>
#include "snippet_parser.h"
#include "snippet_binary_tree.h"

char *file_contents(char *);



//void add_snippet_to_tree(snippet_tree *tree, snippet *new_snippet){


snippet_tree *get_snippet_tree(char *data) {

    snippet_tree *tree;

    

}


char *file_contents(char *filename) {

    FILE *f;
    char *contents;
    char *temp;

    int i;
    int contents_length;
    int temp_length;
    int max_temp_length;

    char c;

    /* Open the file for reading */
    f = fopen(filename, "r");

    /* Set contents to NULL */
    contents = NULL;

    /* Set contents_length to 0 */
    contents_length = 0;

    /* Set temp length to 0 */
    temp_length = 0;

    /* Set max temp length */
    max_temp_length = 1000;

    /* Allocate space for temp */
    temp = (char *) malloc(max_temp_length * sizeof(char));

    /* Get first character */
    c = getc(f);

    /* Read in the contents of the file */
    while (c != EOF) {
        /* Store the most recent character */
        temp[temp_length] = c;
        temp_length++;
        /* If temp is full */
        if (temp_length == max_temp_length) {
            /* If contents is unused */
            if (contents_length == 0) {
                /* Allocate space for contents */
                contents = (char *) malloc(max_temp_length * sizeof(char));
                /* Copy temp into contents */
                for (i = 0; i < max_temp_length; i++) {
                    contents[i] = temp[i];
                }
                /* Update lengths */
                contents_length = max_temp_length;
                temp_length = 0;
            }
            /* Otherwise */
            else {
                /* Enlarge contents */
                contents = (char *) realloc(contents,
                    (contents_length + max_temp_length) * sizeof(char));
                /* Copy temp into contents */
                for (i = 0; i < max_temp_length; i++) {
                    contents[contents_length + i] = temp[i];
                }
                /* Update lengths */
                contents_length += max_temp_length;
                temp_length = 0;
            }
        }
        /* Get next character */
        c = getc(f);
    }

    /* Close the file */
    fclose(f);

    /* Fill in the rest of contents */
    contents = (char *) realloc(contents,
        (contents_length + temp_length + 1) * sizeof(char));
    for (i = 0; i < temp_length; i++) {
        contents[contents_length + i] = temp[i];
    }
    contents[contents_length + temp_length] = '\0';

    /* Free temp */
    free(temp);

    return contents;

}
