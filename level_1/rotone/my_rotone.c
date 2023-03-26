#include <unistd.h>

// =========================aux==============================//
static int rotone(char c) { return c - 25; }
static int my_putchar(char c) { return (write(1, &c, 1)); }
static int is_alpha(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// =========================main==============================//
int main(int argc, char **argv) {
    char *s = argv[1];
    if (argc != 2 || !argv[1]) {
        return my_putchar('\n');
    }

    while (*s) {
        if (*s == 'z' || *s == 'Z')
            my_putchar(rotone(*s));
        else if (!is_alpha(*s))
            my_putchar(*s);
        else
            my_putchar(*s + 1);
        s++;
    }
    my_putchar('\n');
}
