#include <stdio.h>
#include <unistd.h>

static  int my_putchar(char c) {
    write(1, &c, 1);
    return 0;
}

static  void my_putnbr(int nbr) {
    if (nbr > 9) my_putnbr(nbr / 10);
    my_putchar((nbr % 10) + '0');
}

int main(int argc, char **argv) {
    (void)argv;
    my_putnbr(argc - 1);
	my_putchar('\n');
}
