#include <stdio.h>

// numbers that are power of two have an interesting property when represeted in
// base two: they all are the "mirror image" (one's complement) of themselves
// minus one. Uniting this knowledge with the fact that all & operations between
// complementary binary numbers are zero, we get to the simple and efficient
// (constant time operation, O(1)) one-liner below:

int my_is_power_of_2(int n) {
    return (n > 1 && (n & (n - 1)) == 0);
}

// #include <assert.h>
// int main() {
//   assert(my_is_power_of_2(0) == 0);
//   assert(my_is_power_of_2(1) == 0);
//   assert(my_is_power_of_2(2) == 1);
//   assert(my_is_power_of_2(3) == 0);
//   assert(my_is_power_of_2(4) == 1);
//   assert(my_is_power_of_2(5) == 0);
//   assert(my_is_power_of_2(6) == 0);
//   assert(my_is_power_of_2(7) == 0);
//   assert(my_is_power_of_2(8) == 1);
//   assert(my_is_power_of_2(9) == 0);
//   assert(my_is_power_of_2(10) == 0);
//   assert(my_is_power_of_2(11) == 0);
//   assert(my_is_power_of_2(12) == 0);
//   assert(my_is_power_of_2(13) == 0);
//   assert(my_is_power_of_2(14) == 0);
//   assert(my_is_power_of_2(15) == 0);
//   assert(my_is_power_of_2(16) == 1);
//   assert(my_is_power_of_2(32) == 1);
//   assert(my_is_power_of_2(64) == 1);
//   assert(my_is_power_of_2(128) == 1);
//   assert(my_is_power_of_2(256) == 1);
//   assert(my_is_power_of_2(512) == 1);
//   printf("all tests passed!\n");
// }
