#include <unistd.h>

static void my_putstr(char *str) {
    while (str && *str) write(1, str++, 1);
}

static int is_upper(char c) { return (c >= 'A' && c <= 'Z'); }
static int is_lower(char c) { return (c >= 'a' && c <= 'z'); }
static void to_upper(char *c) { *c -= 32; }
static void to_lower(char *c) { *c += 32; }

int main(int argc, char **argv) {
    char *str;
    char *str_ptr;

    if (argc != 2) return (write(1, "\n", 1));
    str = str_ptr = argv[1];
    while (*str_ptr) {
        if (is_upper(*str_ptr))
            to_lower(str_ptr);
        else if (is_lower(*str_ptr))
            to_upper(str_ptr);
        str_ptr++;
    }
    my_putstr(str);
    write(1, "\n", 1);
}
