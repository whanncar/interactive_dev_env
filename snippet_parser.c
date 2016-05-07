#include <stdlib>
#include <string>

#define DESCRIPTION_START_TAG "<description>"
#define DESCRIPTION_END_TAG "</description>"
#define DESCRIPTION_TAG_LENGTH 13

snippet *parse_snippet(char *raw_snippet) {

    snippet *s = (snippet *) malloc(sizeof(snippet));    

}

int *get_description_bounds(char *raw_snippet) {

    int bounds[2];

    int i, j, found_tag;

    char *d_start_tag = DESCRIPTION_START_TAG;
    char *d_end_tag = DESCRIPTION_END_TAG;

    for (i = 0; raw_snippet[i + DESCRIPTION_TAG_LENGTH] != '\0'; i++) {

        found_tag = 1;

        for (j = 0; j < DESCRIPTION_TAG_LENGTH; j++) {

            if (raw_snippet[i + j] != d_start_tag[j]) {

                

            }
            

        }

    }

}



int *get_block_bounds(char *raw_snippet,
                      char *start_tag, int start_tag_length,
                      char *end_tag, int end_tag_length)
{

    int bounds[] = {-1, -1};

    int i, j, found_tag;

    for (i = 0; raw_snippet[i + start_tag_length] != '\0'; i++) {

        found_tag = 1;

        for (j = 0; j < start_tag_length; j++) {

            

        }

    }

}


void free_snippet(snippet *s) {

    /* Do I need to free? Will these live on the heap? UNRESOLVED */
    free(s->pseudocode);
    free(s->description);
    free(s->code);

    free(s);

}
