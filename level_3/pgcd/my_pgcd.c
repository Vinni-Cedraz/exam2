#include <stdlib.h>
#include <stdio.h>

static inline int gcd(int a, int b) {
    if (!b) return a;
    return (gcd(b, a % b));
}

int main(int ac, char **av) {
    if (ac != 3) return printf("\n");
    int a = atoi(av[1]);
    int b = atoi(av[2]);
    printf("%d\n", gcd(a, b));
}
