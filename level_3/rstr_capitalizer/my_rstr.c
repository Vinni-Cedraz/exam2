#include <unistd.h>

static inline int is_upper(char c) { return (c >= 'A') && (c <= 'Z'); }
static inline int is_alpha(char c) { return (c >= 'a' && c <= 'z'); }
static inline int my_putchar(char c) { return (write(1, &c, 1)); }

static inline int is_last_char(char *c) {
    if ((*c != ' ' || *c != '\t') &&
        (*(c + 1) == '\0' || *(c + 1) == '\t' || *(c + 1) == ' '))
        return (1);
    return (0);
}

static inline void my_rstr(char *s) {
    while (*s) {
        if (!is_last_char(s) && !is_upper(*s)) {
            my_putchar(*s);
        } else if (is_last_char(s) && !is_upper(*s) && is_alpha(*s)) {
            my_putchar((*s) - 32);
        } else if (!is_last_char(s) && is_upper(*s)) {
            my_putchar((*s) + 32);
        } else if (is_last_char(s) && is_upper(*s)) {
            my_putchar(*s);
        } else
            my_putchar(*s);
        s++;
    }
}

int main(int ac, char **av) {
    if (ac == 1) return my_putchar('\n');
    int i = 0;
    while (i++ < ac - 1) {
        my_rstr(av[i]);
        my_putchar('\n');
    }
}
