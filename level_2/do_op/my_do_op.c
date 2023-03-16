#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c) { write(1, &c, 1); }

void my_putnbr(int nbr) {
  if (nbr < 0){
	my_putchar('-');
	nbr = -nbr;
  }
  if (nbr > 9)
	my_putnbr(nbr / 10);
  my_putchar(nbr % 10 + '0');
}

int main (int argc, char **argv)
{
	if (argc != 4)
	  return(write(1, "\n", 1));
	int a, b, c = 0;
	a = atoi(argv[1]);
	b = atoi(argv[3]);
	if (*argv[2] == '*')
	  c = a * b;
	else if (*argv[2] == '/')
	  c = a / b;
	else if (*argv[2] == '+')
	  c = a + b;
	else if (*argv[2] == '-')
	  c = a + b;
	else if (*argv[2] == '%')
	  c = a + b;
	my_putnbr(c);
	write(1, "\n", 1);
}
