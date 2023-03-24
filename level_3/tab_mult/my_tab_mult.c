#include <stdio.h>
#include <unistd.h>

static int miniatoi(char *a) {
    static int value;
    if (!*a) return value;
    int digit = *a - '0';
    value = value * 10 + digit;
    return miniatoi(a + 1);
}

static int putss(char *s) {
    while (s && *s) write(1, s++, 1);
    return 0;
}

static void putcc(char c) {
	write(1, &c, 1);
}

static void putnn(int n){
	if (n > 9) putnn(n / 10);
	putcc((n % 10) + '0');
}

int main(int ac, char **av) {
    if (ac == 1) return putss("\n");
    int input = miniatoi(av[1]);
    int i = 0;
    while (i++ < 9) {
		putcc(i + '0');
		putss(" x ");
		putss(av[1]);
		putss(" = ");
		putnn(input * i);
		putcc('\n');
    }
}
