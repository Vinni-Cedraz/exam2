#include <stdio.h>

static inline unsigned int gcd(unsigned int a, unsigned int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

unsigned int lcm(unsigned int a, unsigned int b) {
    int aa = (int)a;
    int bb = (int)b;
	if (aa <= 0 || bb <= 0) return 0;
    return (a * b / gcd(a, b));
}
