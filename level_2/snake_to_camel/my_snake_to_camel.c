#include <unistd.h>

static int	my_putchar(char c);
static void	my_snake_to_camel(char *s);
static void	put_upper(char c, char **s);

int	main(int argc, char **argv) {
	if (argc != 2)
		return (my_putchar('\n'));
	my_snake_to_camel(argv[1]);
	my_putchar('\n');
}

static void	my_snake_to_camel(char *s) {
	while (s && *s)
	{
		if (*s == '_')
			put_upper(*s, &s);
		if (*s != '_')
			my_putchar(*s++);
	}
}

static int	my_putchar(char c) {
	return(write(1, &c, 1));
}

static void	put_upper(char c, char **s) {
	(*s)++, my_putchar(**s - 32), (*s)++;
}
