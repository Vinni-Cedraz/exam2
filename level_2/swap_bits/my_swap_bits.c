#include <unistd.h>

#include "../print_bits/my_print_bits.c"
unsigned char my_swap_bits(unsigned char octet) {
    unsigned char rev = 0;
    rev = (rev | (octet >> 4));
    rev = (rev | (octet << 4));
    return rev;
}

// int main() {
//     unsigned char num1 = 0b11111100;
// 	print_bits(num1);
//     my_putchar('\n');
//     print_bits(my_swap_bits(num1));
//     my_putchar('\n');
//
//     unsigned char num2 = 0b11111111;
// 	print_bits(num2);
//     my_putchar('\n');
//     print_bits(my_swap_bits(num2));
//     my_putchar('\n');
//
//     unsigned char num3 = 0b01010101;
// 	print_bits(num3);
//     my_putchar('\n');
//     print_bits(my_swap_bits(num3));
//     my_putchar('\n');
//
//     unsigned char num4 = 0b10000000;
// 	print_bits(num4);
//     my_putchar('\n');
//     print_bits(my_swap_bits(num4));
//     my_putchar('\n');
//
//     unsigned char num5 = 0b00110001;
// 	print_bits(num5);
//     my_putchar('\n');
//     print_bits(my_swap_bits(num5));
//     my_putchar('\n');
//
//     return 0;
// }
