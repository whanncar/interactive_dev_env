



char *copy_substring(char *str, int len) {

    int i;
    char *substr;

    /* Allocate space for the copy */
    substr = (char *) malloc((len + 1) * sizeof(char));
    /* Copy the substring */
    for (i = 0; i < len; i++) {
        substr[i] = str[i];
    }
    /* Add an end of string delimiter */
    substr[len] = '\0';

    return substr;
}

int string_length(char *s) {

    int i;

    for (i = 0; s[i] != '\0'; i++);

    return i;

}





