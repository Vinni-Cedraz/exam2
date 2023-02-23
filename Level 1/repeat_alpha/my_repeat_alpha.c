#include <unistd.h>

static int			how_many_times(char c);
static void 		repeat_alpha(char c, int j);
static int			my_putchar(char c);
static int			is_lower(char c);
static int			is_upper(char c);
static void			init_variables(char *, char **, int *, int *, char **);

int	main(int argc, char **argv)
{
	char	c;
	char	*argv_str;
	int		i;
	int		j;

	if (argc != 2)
		return(my_putchar('\n'));
	init_variables(&c, &argv_str, &i, &j, argv);
	while (c)
	{
		c = argv_str[i];
		j = how_many_times(c);
		repeat_alpha(c, j);
		i++;
	}
	my_putchar('\n');
}

static void	init_variables(char *c, char **str, int *i, int *j, char **argv)
{
	str = argv;
	*str = argv[1];
	*c = '*';
	*i = 0;
	*j = 0;
}

static inline int	how_many_times(char c)
{
	int	times;

	if (is_upper(c))
		times = c - 64;
	else if (is_lower(c))
		times = c - 96;
	else
		times = 1;
	return (times);
}

static inline void repeat_alpha(char c, int j)
{
	while (j--)
		my_putchar(c);
}

static inline int	my_putchar(char c)
{
	return (write(1, &c, 1));
}

static inline int	is_lower(char c)
{
	return (c <= 122 && c >= 97);
}

static inline int	is_upper(char c)
{
	return (c >= 65 && c <= 90);
}
