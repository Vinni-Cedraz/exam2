#include <unistd.h>

static int my_putnstr(char *str, int n) {
    while (n-- && *str) write(1, str++, 1);
    write(1, " ", 1);
    return 0;
}

static char *next_word(char *s) {
    while (*s != ' ' && *s != '\t' && *s != '\0') s++;
    if (!*s) return (NULL);
    return (s + 1);
}

static char my_strlen(char *str) {
    char *end = str;
    while (*end && *end != ' ' && *end != '\t') end++;
    return end - str;
}

static void create_str_stack(char *s) {
    if (next_word(s)) create_str_stack(next_word(s));
    my_putnstr(s, my_strlen(s));
}

int main(int ac, char **av) {
    if (ac != 2) return (write(1, "\n", 1));
    create_str_stack(av[1]);
    write(1, "\n", 1);
}
