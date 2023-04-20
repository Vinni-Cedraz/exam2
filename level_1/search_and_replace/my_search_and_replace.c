#include <unistd.h>

static int putendl(char *str);
static int not_single_char(char *str) { return (str[1] != '\0'); }
static void search_and_replace(char *s, char to_be_replaced, char replacement);

int main(int argc, char **argv) {
    char *string;
    char to_be_replaced;
    char replacement;

    if (argc != 4 || not_single_char(argv[2]) || not_single_char(argv[3]))
        return (putendl(""));
    string = argv[1];
    to_be_replaced = argv[2][0];
    replacement = argv[3][0];
    if (!replacement && !to_be_replaced) return (putendl(""));
    search_and_replace(string, to_be_replaced, replacement);
    putendl(string);
}

static void search_and_replace(char *str, char c, char replacement) {
    while (*str) {
        if (*str == c) *str = replacement;
        str++;
    }
}

static int putendl(char *str) {
    while (str && *str) write(1, str++, 1);
    return (write(1, "\n", 1));
}
