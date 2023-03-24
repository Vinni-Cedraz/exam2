#include <unistd.h>

static char *next_word(char *s) {
    while (*s != ' ' && *s != '\t' && *s != '\0') s++;
    if (!*s) return (NULL);
    return (s + 1);
}

static void my_putnstr(char *str, int n, int is_last_word) {
    while (n-- && *str) write(1, str++, 1);
    if (!is_last_word) write(1, " ", 1);
}

static char my_strlen(char *str) {
    char *end = str;
    while (*end && *end != ' ' && *end != '\t') end++;
    return end - str;
}

static void my_rev_wstr(char *s, int is_last_word) {
    char *next = next_word(s);
    if (next) my_rev_wstr(next, 0);
    my_putnstr(s, my_strlen(s), is_last_word);
}

// remember recursion is LIFO, so the first word in av[1] is gonna be put last,
// that's why first call has the is_last_word flag set to true
int main(int ac, char **av) {
    if (ac != 2) return (write(1, "\n", 1));
    my_rev_wstr(av[1], 1);
    write(1, "\n", 1);
}
