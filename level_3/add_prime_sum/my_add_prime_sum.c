#include <stdio.h>
#include <unistd.h>

static inline int is_prime(int nb);
static inline void my_putnbr(int nb);
static inline void my_putchar(char c) { write(1, &c, 1); };
static inline int simple_atoi(char *str);

int main(int argc, char *argv[]) {
    int i = -1;
    int sum = 0;
	int num = simple_atoi(argv[1]);
    if (argc != 2 || num < 1) my_putnbr(0), my_putchar('\n');
    while (++i <= num)
        if (is_prime(i)) sum += i;
    my_putnbr(sum);
    my_putchar('\n');
}

static inline int my_strlen(char *str){
	char *end = str;
	while (end && *end) end++;
	return end - str;
}

static inline int simple_atoi(char *str) {
	int toi, zeros, len;
	toi = 0, zeros = 1, len = my_strlen(str);

	while (len--) {
		toi += (str[len] - '0') * zeros;
		zeros *= 10;
	}
	return toi;
}

static inline void my_putnbr(int nb) {
    if (nb > 9) my_putnbr(nb / 10);
    my_putchar(nb % 10 + '0');
}

static inline int is_prime(int nb) {
    int i = 2;
    if (nb == 1) return (0);
    while (i <= nb / 2) {
        if (nb % i == 0) return (0);
        i++;
    }
    return (1);
}
