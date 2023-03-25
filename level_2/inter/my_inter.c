#include <unistd.h>

static int it_is_there(char current_char, char *argv2);
static int not_already_printed(char c);
static int my_putchar(char c);

int main(int argc, char **argv) {
    char *str1 = argv[1] - 1;

    if (argc != 3 || !argv[1] || !argv[2]) return my_putchar('\n');
    while (*(++str1))
        if (it_is_there(*str1, argv[2]) && not_already_printed(*str1))
            my_putchar(*str1);
    my_putchar('\n');
}

static int it_is_there(char current_char, char *argv2) {
    while (*argv2)
        if (current_char == *argv2++) return 1;
    return 0;
}

static int not_already_printed(char c) {
    int search_index = 0;
    static int placement_index;
    static char printed[__INT_MAX__] = {0};

    while (printed[search_index])
        if (printed[search_index++] == c) return 0;
    printed[placement_index++] = c;
    return 1;
}

static int my_putchar(char c) {
    write(1, &c, 1);
    return (0);
}
