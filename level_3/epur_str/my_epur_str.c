#include <unistd.h>

static  int is_whitespace(char c) { return (c == ' ' || c == '\t'); }

static  char *next_char(char *str) {
    while (*str && is_whitespace(*str)) str++;
    if (*str == '\0') return (NULL);
    return str;
}

static  int my_putchar(char c) {
    write(1, &c, 1);
    return 0;
}

int main(int argc, char **argv) {
    char *str = argv[1];
    if (argc != 2 || *str == '\0') return my_putchar('\n');
    str = next_char(str);
    while (str && *str) {
        if (!is_whitespace(*str))
            my_putchar(*str++);
        else {
            if (*(str + 1) != '\0') my_putchar(' ');
            str = next_char(str);
        }
    }
    my_putchar('\n');
}
