#include <unistd.h>

static void my_putchar(char c);
static void my_snake_to_camel(char *s);
static void put_upper(char c, char **s);

int main(int argc, char **argv) {
    my_snake_to_camel(argv[1]);
    my_putchar('\n');
}

static inline void my_snake_to_camel(char *s) {
    while (s && *s) {
        if (*s == '_') put_upper(*s, &s);
        if (*s != '_') my_putchar(*s++);
    }
}

static inline void my_putchar(char c) { write(1, &c, 1); }

static inline void put_upper(char c, char **s) {
    (*s)++, my_putchar(**s - 32), (*s)++;
}
