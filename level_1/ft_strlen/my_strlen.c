int my_strlen(char *str) {
    char *start = str;
    if (str)
        while (*str) str++;
    return (str - start);
}
