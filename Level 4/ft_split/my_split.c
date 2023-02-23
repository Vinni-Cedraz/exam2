#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void			lenstrcopy(char *s1, char *s2, int len);
static int			is_whitespace(char c);
static char			*next_whitespace(char *str);
static char			*next_valid_char(char *str);
static int			wordcounter(char *str);

char	**my_split(char *str)
{
	int		index;
	int		word_count;
	char	*start;
	char	*end;
	char	**split;

	index = -1;
	word_count = wordcounter(str);
	split = malloc(sizeof(char *) * (word_count + 1));
	split[word_count] = NULL;
	while (++index < word_count)
	{
		start = next_valid_char(str);
		end = next_whitespace(start);
		split[index] = malloc((end - start) + 1);
		lenstrcopy(split[index], start, end - start);
		str = end;
	}
	return (split);
}

static inline int	wordcounter(char *s)
{
	int	inside_word;
	int	words;

	inside_word = 0;
	words = 0;
	while (*s)
	{
		if (is_whitespace(*s))
			inside_word = 0;
		else if (!inside_word)
		{
			words++;
			inside_word = 1;
		}
		s++;
	}
	return (words);
}

static inline void	lenstrcopy(char *s1, char *s2, int len)
{
	int	i;

	i = -1;
	while (++i < len && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
}

static inline int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

static inline char	*next_whitespace(char *str)
{
	while (!is_whitespace(*str))
		str++;
	return (str);
}

static inline char	*next_valid_char(char *str)
{
	while (is_whitespace(*str))
		str++;
	return (str);
}

// ------------------TEST-FUCKING-TEST----------------------//

#include <stdio.h>
#include <stdlib.h>

static void			my_free_arr(char **arr, void **aux);
static void			print_arr(char **arr);

int	main(void)
{
	char	*s;
	char	**split;

	s = "         Hello World, this is a     test		";
	split = my_split(s);
	print_arr(split);
	my_free_arr(split, (void **)split);
	return (0);
}

static inline void	my_free_arr(char **arr, void **aux)
{
	while (arr && *arr)
		free(*arr++);
	free(aux);
}

static inline void	print_arr(char **arr)
{
	while (*arr)
		printf("%s\n", *arr++);
}
