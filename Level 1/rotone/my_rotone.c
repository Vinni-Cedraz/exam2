#include <unistd.h>

static int			my_putchar(char c);
static int			is_alpha(char c);
static void			my_rotone(char *str);

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
		return (my_putchar('\n'));
	my_rotone(argv[1]);
	my_putchar('\n');
}

static inline int	my_putchar(char c)
{
	return (write(1, &c, 1));
}

static inline void	my_rotone(char *str)
{
	char	c;
	int		i;

	c = '*';
	i = -1;
	while (c)
	{
		c = str[++i];
		if (c == 'z' || c == 'Z')
			my_putchar(c - 25);
		else if (!is_alpha(c))
			my_putchar(c);
		else
			my_putchar(c + 1);
	}
}

static inline int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
