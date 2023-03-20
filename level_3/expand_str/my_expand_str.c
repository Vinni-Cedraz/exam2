#include <unistd.h>

static inline int my_putchar(char c) {
    write(1, &c, 1);
    return 0;
}

static inline int is_whitespace(char c) { return (c == ' ' || c == '\t'); }
static inline char *next_word(char *s) {
    while (*s && is_whitespace(*s)) s++;
    if (*s == '\0') return NULL;
    return s;
}

int main(int argc, char **argv) {
    char *s = argv[1];
	if (argc != 2 || *s == '\0')
		return (my_putchar('\n'));
	s = next_word(s);
    while (*s) {
        if (!is_whitespace(*s))
            my_putchar(*s++);
        else {
            if (*(s + 2) != '\0')
                my_putchar(' '), my_putchar(' '), my_putchar(' ');
            s = next_word(s);
        }
    }
	my_putchar('\n');
}
