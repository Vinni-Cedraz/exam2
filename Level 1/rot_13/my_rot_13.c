#include <unistd.h>

static int			my_putchar(char c);
static int			is_lower(char c);
static int			is_upper(char c);
static int			is_beyond_end_of_alphabet(char c);
static int			alphabet_position(char c);
static int			is_alpha(char c);
static void			my_rot_13(char c);

int	main(int argc, char **argv)
{
	char	*str;
	int		i;

	i = 0;
	if (argc != 2)
		return (my_putchar('\n'));
	str = argv[1];
	while (str[i])
	{
		if (!is_alpha(str[i]))
			my_putchar(str[i]);
		else if (is_beyond_end_of_alphabet(str[i]))
			my_rot_13(str[i]);
		else
			my_putchar(str[i] + 13);
		i++;
	}
	return (my_putchar('\n'));
}

static inline int	my_putchar(char c)
{
	return (write(1, &c, 1));
}

static inline int	is_beyond_end_of_alphabet(char c)
{
	int	i;

	i = alphabet_position(c);
	return (i >= 14);
}

static inline void	my_rot_13(char c)
{
	int	i;

	if (is_lower(c))
	{
		i = (alphabet_position(c) + 13) % 26;
		my_putchar(i + 96);
	}
	if (is_upper(c))
	{
		i = (alphabet_position(c) + 13) % 26;
		my_putchar(i + 64);
	}
}

static inline int	alphabet_position(char c)
{
	int	i;

	i = 0;
	if (is_upper(c))
		i = (c + 1) - 'A';
	else if (is_lower(c))
		i = (c + 1) - 'a';
	return (i);
}

static inline int	is_alpha(char c)
{
	return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z');
}
static inline int	is_lower(char c)
{
	return (c <= 122 && c >= 97);
}
static inline int	is_upper(char c)
{
	return (c >= 65 && c <= 90);
}
