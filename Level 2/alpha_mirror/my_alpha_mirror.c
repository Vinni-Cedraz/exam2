#include <unistd.h>

static int			ft_putchar(char c);
static int			ascii_convert(int pos, char c);
static int			alpha_pos(char c);
static int			alpha_mirror(char c);
static int			is_alpha(char c);

int	main(int argc, char *argv[])
{
	int		i;
	char	c;
	int		mirrored_position;

	c = 1;
	i = -1;
	if (argc != 2)
		return (ft_putchar('\n'));
	while (c)
	{
		c = argv[1][++i];
		mirrored_position = alpha_mirror(c);
		if (mirrored_position)
			c = ascii_convert(mirrored_position, c);
		ft_putchar(c);
	}
	ft_putchar('\n');
}

static inline int	alpha_mirror(char c)
{
	double	mirror_dist;
	double	mirrored_position;

	if (!is_alpha(c))
		return (0);
	mirror_dist = 13.5 - alpha_pos(c);
	mirrored_position = (2 * mirror_dist) + alpha_pos(c);
	return (mirrored_position);
}

static inline int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

static inline int	ft_putchar(char c)
{
	if (!c)
		return (0);
	return (write(1, &c, 1));
}

static inline int	alpha_pos(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 96);
	else if (c >= 'A' && c <= 'Z')
		return (c - 64);
	else
		return (0);
}

static inline int	ascii_convert(int pos, char c)
{
	if (!pos)
		return (0);
	if (c >= 'a' && c <= 'z')
		return (pos + 96);
	return (pos + 64);
}
