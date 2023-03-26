#include "my_strcpy.c"
#include <stdlib.h>
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
	char *dest = malloc(256);
	char src[] = "ok, this here gotta be in dest now";

	// dest = NULL;
	my_strcpy(dest, src);
	my_putstr(dest);
	// my_putstr(src);
}
