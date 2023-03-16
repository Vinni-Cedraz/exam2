#include <unistd.h>

static void			to_upper(char *c);
static void			to_lower(char *c);
static int			is_upper(char c);
static int			is_lower(char c);
static void			my_putstr(char *str);

int	main(int argc, char **argv)
{
	char	*str;
	char	*rev_case_str;

	if (argc != 2)
		return (write(1, "\n", 1));
	str = rev_case_str = argv[1];
	while (*rev_case_str)
	{
		if (is_upper(*rev_case_str))
			to_lower(rev_case_str);
		else if (is_lower(*rev_case_str))
			to_upper(rev_case_str);
		rev_case_str++;
	}
	my_putstr(str);
	write(1, "\n", 1);
}

static inline int	is_upper(char c){
	return (c >= 'A' && c <= 'Z');
}
static inline int	is_lower(char c){
	return (c >= 'a' && c <= 'z');
}
static inline void	to_upper(char *c){
	*c -= 32;
}
static inline void	to_lower(char *c){
	*c += 32;
}
static inline void	my_putstr(char *str){
	while (str && *str)
		write(1, str++, 1);
}
