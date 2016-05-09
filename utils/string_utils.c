

int prefix_match_length(char *str1, char *str2) {

    int i;

    for (i = 0; str1[i] != '\0', str2[i] != '\0', str1[i] == str2[i]; i++);

    return i;

}

int is_alphanumeric(char c) {

    return ('0' <= c && c <= '9') ||
           ('a' <= c && c <= 'z') ||
           ('A' <= c && c <= 'Z');

}

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





