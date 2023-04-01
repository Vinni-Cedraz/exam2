#include <stdlib.h>
#include <stdio.h>

// HCF(Highest Common Denominator) and GCD (Greatest Common Denominator)
// are the same thing

static int gcd(int a, int b) {

    // if moulinette isn't approving you , try adding this int overflow **check

    if (!b) return a;
    return (gcd(b, a % b));
}

int main(int ac, char **av) {
    if (ac != 3) return printf("\n");
    int a = atoi(av[1]);
    int b = atoi(av[2]);
    printf("%d\n", gcd(a, b));
}

// the tests are in the Makefile, add more as necessary

// **check:
// it shouldnt be necessary in other contexts but moulinette can be an asshole:

// int check_overflow_a = (int)a;
// int check_overflow_b = (int)b;
// if (check_overflow_a <= 0 || check_overflow_b <= 0) return 0;
