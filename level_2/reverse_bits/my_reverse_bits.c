#include "../print_bits/print_bits.c"

void my_putchar(unsigned char c);

unsigned char my_reverse_bits(unsigned char octet) {
	unsigned char rev = 0;
	short counter = 8;
	while (counter--) {
		rev <<= 1;  
		rev = (rev | (octet & 1));
		octet >>= 1;
	}
	return rev;
}

void my_putchar(unsigned char c) { write(1, &c, 1); }

int main() {
  unsigned char num1 = 0b11111100;
  print_bits(my_reverse_bits(num1)); // should print "00000000\n"
  my_putchar('\n');
  // my_reverse_bits_rec(num1); // should print "00000000\n"
  // my_putchar('\n'));

  unsigned char num2 = 0b11111111;
  print_bits(my_reverse_bits(num2)); // should print "11111111\n"
  my_putchar('\n');
  // my_reverse_bits_rec(num2); // should print "11111111\n"
  // my_putchar('\n');

  unsigned char num3 = 0b01010101;
  print_bits(my_reverse_bits(num3)); // should print "01010101\n"
  my_putchar('\n');
  // my_reverse_bits_rec(num3); // should print "01010101\n"
  // my_putchar('\n');

  unsigned char num4 = 0b10000000;
  print_bits(my_reverse_bits(num4)); // should print "10000000\n"
  my_putchar('\n');
  // my_reverse_bits_rec(num4); // should print "10000000\n"
  // my_putchar('\n');

  unsigned char num5 = 0b00110001;
  print_bits(my_reverse_bits(num5)); // should print "00110001\n"
  my_putchar('\n');
  // my_reverse_bits_rec(num5); // should print "00110001\n"
  // my_putchar('\n');

  return 0;
}
