#include <stdio.h>

static inline unsigned int gcd(unsigned int a, unsigned int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

unsigned int lcm(unsigned int a, unsigned int b) {
	return (a * b / gcd(a, b));
}