#include <unistd.h>

static int my_putchar(char c);
static int was_not_already_printed(char c);

int main(int argc, char **argv) {
    if (argc != 3) return my_putchar('\n');

    char *str1 = argv[1];
    char *str2 = argv[2];
    while (*str1) {
        if (was_not_already_printed(*str1)) my_putchar(*str1);
        str1++;
    }
    while (*str2) {
        if (was_not_already_printed(*str2)) my_putchar(*str2);
        str2++;
    }
    my_putchar('\n');
}

static inline int was_not_already_printed(char c) {
    int search_index = 0;
    static int placement_index;
    static char printed[__INT_MAX__] = {0};

    while (printed[search_index])
        if (printed[search_index++] == c) return 0;
    printed[placement_index++] = c;
    return 1;
}

static inline int my_putchar(char c) {
    write(1, &c, 1);
    return 0;
}
