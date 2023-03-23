#include <stdio.h>
#include <unistd.h>

static inline int my_putchar(char c) {
    write(1, &c, 1);
    return 0;
}

static inline int my_strlen(char *str) {
    char *end = str;
    while (end && *end) end++;
    return end - str;
}

static inline int simple_atoi(char *a) {
    int toi = 0;
    int len = my_strlen(a);
    int zeros = 1;
    while (1) {
        toi += (a[--len] - '0') * zeros;
        zeros *= 10;
        if (len == 0) break;
    }
    return (toi);
}

static inline void print_hex(int dec) {
    static const char hex[16] = "0123456789abcdef";
    if (dec >= 16) print_hex(dec / 16);
    my_putchar(hex[dec % 16]);
}

int main(int ac, char **av) {
    if (ac != 2) return (my_putchar('\n'));
    int dec = simple_atoi(av[1]);
    print_hex(dec);
    my_putchar('\n');
}
