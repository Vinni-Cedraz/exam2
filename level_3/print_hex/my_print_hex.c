#include <stdio.h>
#include <unistd.h>

static int miniatoi(char *a, int toi) {
    if (!*a) return toi;
    toi = toi * 10 + *a - '0';
    return miniatoi(a + 1, toi);
}

static void print_hex(int dec) {
    static const char hex[16] = "0123456789abcdef";
    if (dec >= 16) print_hex(dec / 16);
    write(1, &hex[dec % 16], 1);
}

int main(int ac, char **av) {
    if (ac != 2) return (write(1, "\n", 1));
    int dec = miniatoi(av[1], 0);
    print_hex(dec);
    write(1, "\n", 1);
}
