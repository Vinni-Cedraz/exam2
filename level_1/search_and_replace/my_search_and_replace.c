#include <unistd.h>

static int my_putstr(char *str);
static int is_single_char(char *c);
static void search_and_replace(char *s, char to_be_replaced, char replacement);

int main(int argc, char **argv) {
    char *string;
    char to_be_replaced;
    char replacement;

    string = argv[1];
    if (argc != 4) return (my_putstr(""));
    if (is_single_char(argv[2])) to_be_replaced = argv[2][0];
    if (is_single_char(argv[3])) replacement = argv[3][0];
    if (!replacement && !to_be_replaced) return (my_putstr(""));
    search_and_replace(string, to_be_replaced, replacement);
    my_putstr(string);
}

static int is_single_char(char *c) { return (c[1] == '\0'); }

static void search_and_replace(char *str, char c,
                               char replacement) {
    int i = -1;
    while (str[++i])
        if (str[i] == c) str[i] = replacement;
}

static int my_putstr(char *str) {
    while (str && *str) write(1, str++, 1);
    return (write(1, "\n", 1));
}
