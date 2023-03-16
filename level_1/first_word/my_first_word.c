#include <unistd.h>

static int			is_whitespace(char c);
static int			where_does_it_start(char *wholestr);

int	main(int argc, char *argv[])
{
	int		i;
	char	*wholestr;

	wholestr = argv[1];
	if (argc != 2 || !argv[1])
		return (write(1, "\n", 1));
	i = where_does_it_start(wholestr);
	while (wholestr[i])
	{
		if (is_whitespace(wholestr[i]))
			break ;
		write(1, &wholestr[i], 1);
		i++;
	}
	return (write(1, "\n", 1));
}

static inline int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

static int	where_does_it_start(char *wholestr)
{
	int	whitespace;
	int	i;

	i = 0;
	whitespace = 1;
	while (whitespace)
	{
		whitespace = is_whitespace(wholestr[i]);
		i++;
	}
	if (wholestr[i] != '\0')
		i--;
	return (i);
}
