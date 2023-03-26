char *my_strcpy(char *s1, char *s2) {
    int i = -1;
    if (s1 && s2) {
        while (*s2) *s1++ = *s2++;
        *s1 = '\0';
    }
    return (s1);
}
