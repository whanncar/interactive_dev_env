/*
 * Need to add description here UNRESOLVED 
 *
 */

#include <stdlib>
#include <stdio>
#include <string>

#define DESCRIPTION_START_TAG "<description>"
#define DESCRIPTION_END_TAG "</description>"
#define DESCRIPTION_TAG_LENGTH 13

char **get_block(char *, tag_list *);
char **get_substring(char *, int, int);
int *get_block_bounds(char *, char *, int, char *, int);



/*
 * parse_snippet: Converts a raw snippet into a snippet
 *
 * arguments: raw_snippet: The raw snippet string
 *            tag_list: The list of tags corresponding to fields
 *                      in the snippet
 *
 * return value: Pointer to the newly created snippet
 *
 */

snippet *parse_snippet(char *raw_snippet, tag_list *tags) {

    int i;
    char *block;

    /* Allocate space for the snippet */
    snippet *s = (snippet *) malloc(sizeof(snippet)); 

    /* Fill in the fields of the snippet */ 
    for (i = 0; tags != NULL; tags = tags->next, i++) {
        ((char **) s)[i] = get_block(raw_snippet, tags);
    }

    return s;

}



/*
 * get_block: Returns pointer to the block corresponding to the given tag
 *
 * arguments: raw_snippet: The raw snippet in which the block is sought
 *            tag: Pointer to tag_list struct containing information about
 *                 the start and end tags for the block that is sought
 *
 * return value: Pointer to a string containing a copy of the block if
 *               the block is found
 *               NULL otherwise
 *
 */

char **get_block(char *raw_snippet, tag_list *tag) {

    /* Get start position and length of block */
    int *bounds = get_block_bounds(raw_snippet,
                                   *(tag->start_tag), tag->start_tag_length,
                                   *(tag->end_tag), tag->end_tag_length);

    /* If block was not found, return NULL */
    if (bounds[0] == -1) {
        return NULL;
    }

    return get_substring(raw_snippet, bounds[0], bounds[1]);

}



/*
 * get_substring: Gets a copy of the substring of raw_snippet
 *                beginning at "start" which is "length" long
 *
 * arguments: s: String from which the substring is extracted
 *            start: Start position of substring
 *            length: Length of substring to be extracted
 *
 * return value: Copy of the desired substring with the string
 *               termination symbol at the end
 *
 */

char **get_substring(char *s, int start, int length) {

    int i;

    /* Allocate space for the copy */
    char *block = (char *) malloc((length + 1) * sizeof(char));

    /* Copy the substring */
    for (i = 0; i < length; i++) {
        block[i] = s[start + i];
    }

    /* Add string termination character */
    block[length] = '\0';

    return &block;

}



/*
 * get_block_bounds: Finds the block corresponding to a tag in a raw snippet
 *
 * arguments: raw_snippet: The raw snippet to be searched
 *            start_tag: The start tag corresponding to the tag
 *            start_tag_length: The length of the start tag
 *            end_tag: The end tag corresponding to the tag
 *            end_tag_length: The length of the end tag
 *
 * return value: int array "bounds" of length 2
 *               bounds[0] = start position of sought block
 *               bounds[1] = length of sought block
 *
 *               If at least one of the tags was not found,
 *               both entries will be -1
 *
 */

int *get_block_bounds(char *raw_snippet,
                      char *start_tag, int start_tag_length,
                      char *end_tag, int end_tag_length)
{

    int i, j, found_tag;
    int bounds[] = {-1, -1};

    /* For each possible position of the tag */
    for (i = 0; raw_snippet[i + start_tag_length] != '\0'; i++) {
        /* Assume the tag has been found */
        found_tag = 1;
        /* Make sure that the substring matches the tag */
        for (j = 0; j < start_tag_length; j++) {
            /* 
             * If the substring does not match the tag,
             * update found_tag and move on
             */
            if (raw_snippet[i + j] != start_tag[j]) {
                found_tag = 0;
                break;
            }
        }
        /* If the tag was actually found */
        if (found_tag) {
            /* 
             * Store the index of the beginning of the block
             * and move on
             */
            i += start_tag_length + 1;
            bounds[0] = i;
            break;
        }
    }

    /* For each possible position of the tag */
    for (; raw_snippet[i + end_tag_length] != '\0'; i++) {
        /* Assume the tag has been found */
        found_tag = 1;
        /* Make sure that the substring matches the tag */
        for (j = 0; j < end_tag_length; j++) {
            /* 
             * If the substring does not match the tag,
             * update found_tag and move on
             */
            if (raw_snippet[i + j] != end_tag[j]) {
                found_tag = 0;
                break;
            }
        }
        /* If the tag was actually found */
        if (found_tag) {
            /* 
             * Store the index of the character
             * just after the end of the block
             */
            j--;
            bounds[1] = j;
            break;
        }
    }

    /* Update the value of bounds[1] to be the length of the block */
    bounds[1] -= bounds[0];

    /* If either tag was not found, set both values to -1 */
    if (bounds[0] < 0 || bounds[1] < 0) {
        bounds[0] = -1;
        bounds[1] = -1;
    }

    return bounds;

}



/*
 * free_snippet: Frees the snippet struct and its associated data
 *
 * arguments: s: Pointer to snippet to be freed
 *
 */

void free_snippet(snippet *s) {

    /* Do I need to free? Will these live on the heap? UNRESOLVED */
    free(s->pseudocode);
    free(s->description);
    free(s->code);

    free(s);

}



/*
 * print_snippet: Prints the information contained in the given snippet
 *
 * arguments: s: Pointer to snippet whose information will be printed
 *
 */

void print_snippet(snippet *s) {

    /* Print pseudocode */
    printf("\nPseudocode:\n\n");
    if (s->pseudocode != NULL) {
        printf("%s\n", *(s->pseudocode));
    }
    else {
        printf("No pseudocode tag found\n");
    }

    /* Print code */
    printf("\nCode:\n\n");
    if (s->code != NULL) {
        printf("%s\n", *(s->code));
    }
    else {
        printf("No code tag found\n");
    }

}


