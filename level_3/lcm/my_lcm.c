#include <stdio.h>

// the gcd (HCF and GCD are the SAME THING), algorithm used here was the classic
// Euclidean algorithm. A good explanation of it's logic can be found *here.

// I realized that implementing it with recursion was easier for me:
static unsigned int gcd(unsigned int a, unsigned int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

// but recursion is not the only way:
// static unsigned int gcd_not_recursive(unsigned int a, unsigned int b) {
//     int tmp;
//     while (b) {
//         tmp = b;
//         b = a % b;
//         a = tmp;
//     }
//     return a;
// }

unsigned int lcm(unsigned int a, unsigned int b) {

    // if moulinette isn't approving you , try adding this int overflow **check

	if (a == 0 || b == 0) return 0;
    return (a * b / gcd(a, b));
}

// *here: freecodecamp.org/news/euclidian-gcd-algorithm-greatest-common-divisor/

// **check:
// int check_overflow_a = (int)a;
// int check_overflow_b = (int)b;
// if (check_overflow_a <= 0 || check_overflow_b <= 0) return 0;



// TESTS:
#include <assert.h>
int main() {
    assert(lcm(2, 3) == 6);
    assert(lcm(6, 8) == 24);
    assert(lcm(3, 4) == 12);
    assert(lcm(9, 5) == 45);
    assert(lcm(12, 18) == 36);
    assert(lcm(0, 0) == 0);
    assert(lcm(0, 1) == 0);
    assert(lcm(1, 0) == 0);
    assert(lcm(1, 1) == 1);
    assert(lcm(1, 2) == 2);
    assert(lcm(2, 1) == 2);
    assert(lcm(2, 2) == 2);
    assert(lcm(2, 3) == 6);
    assert(lcm(3, 2) == 6);
    assert(lcm(3, 4) == 12);
    assert(lcm(4, 3) == 12);
    assert(lcm(4, 4) == 4);
    assert(lcm(4, 5) == 20);
    assert(lcm(5, 4) == 20);
    assert(lcm(5, 5) == 5);
    assert(lcm(5, 6) == 30);
    assert(lcm(6, 5) == 30);
    assert(lcm(6, 6) == 6);
    assert(lcm(6, 7) == 42);
    assert(lcm(7, 6) == 42);
    assert(lcm(7, 7) == 7);
    assert(lcm(7, 8) == 56);
    assert(lcm(8, 7) == 56);
    assert(lcm(8, 8) == 8);
    assert(lcm(8, 9) == 72);
    assert(lcm(9, 8) == 72);
    assert(lcm(9, 9) == 9);
    assert(lcm(9, 10) == 90);
	printf("All tests passed!");
}
