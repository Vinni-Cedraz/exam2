#include <unistd.h>

static int is_lower(char c) { return (c >= 'a' && c <= 'z'); }
static int is_upper(char c) { return ((c >= 'A' && c <= 'Z')); }
static int is_whitespace(char c) { return (c == ' ' || c == '\t'); }
static int putc(char c) { return write(1, &c, 1); }
static void putstrcapi(char *s);

int main(int ac, char **av) {
    int i = 0;
    if (ac == 1) return putc('\n');
    while (++i < ac) {
        putstrcapi(av[i]);
        putc('\n');
    }
}

static void putstrcapi(char *s) {
    if (!s) return;
    if (is_upper(*s)) putc(*s);
    if (is_lower(*s)) putc((*s) - 32);
    s++;
    while (*s) {
        if (is_whitespace(*(s - 1)) && is_lower(*s))
            putc((*s) - 32);
        else if (is_whitespace(*(s - 1)) && is_upper(*s))
            putc((*s));
        else if (is_upper(*s))
            putc((*s) + 32);
        else
            putc(*s);
        s++;
    }
}
