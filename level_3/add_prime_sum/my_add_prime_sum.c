#include <stdio.h>
#include <unistd.h>

static int is_prime(int nb);
static void my_putnbr(int nb);
static void my_putchar(char c) { write(1, &c, 1); };
static int miniatoi(char *a, int toi);

int main(int argc, char *argv[]) {
    int i = -1;
    int sum = 0;
    int num = miniatoi(argv[1], 0);
    if (argc != 2 || num < 1) my_putnbr(0), my_putchar('\n');
    while (++i <= num)
        if (is_prime(i)) sum += i;
    my_putnbr(sum);
    my_putchar('\n');
}

static int miniatoi(char *a, int toi) {
    if (!*a) return toi;
	int digit = *a - '0';
    toi = toi * 10 + digit;
    return miniatoi(a + 1, toi);
}

static void my_putnbr(int nb) {
    if (nb > 9) my_putnbr(nb / 10);
    my_putchar(nb % 10 + '0');
}

static int is_prime(int nb) {
    int i = 2;
    if (nb == 1) return (0);
    while (i <= nb / 2) {
        if (nb % i == 0) return (0);
        i++;
    }
    return (1);
}
