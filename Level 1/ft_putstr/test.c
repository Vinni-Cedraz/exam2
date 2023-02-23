#include "my_putstr.c"

void	my_putstr(char *str);

int main(void)
{
	my_putstr("Hello World!");
	my_putstr("   HELLO 1234");
	my_putstr("\n");
	my_putstr("\0");
	my_putstr("-91");
	my_putstr("");
}
