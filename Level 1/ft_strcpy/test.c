#include "my_strcpy.c"
#include <unistd.h>
#include <string.h>

static void	my_putstr(char *str)
{
	char	*s;

	s = str;
	if (!s)
		return ;
	while (*str)
		write(1, str++, 1);
}
int main(void)
{
	char dest[256] = "hello world";
	char src[256] = "HELLO";

	my_strcpy(dest, src);
	// strcpy("", src);
	my_putstr(dest);
	my_putstr(src);
}
