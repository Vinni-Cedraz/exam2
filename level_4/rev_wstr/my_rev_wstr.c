#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int					is_whitespace(char c);
static int					putstring(char *s);
static int					my_strlen(char *s);
static int					my_wordcounter(char *s);
static char					*get_word_by_index(int index, char *s, int number_of_words);
static void					ft_free_arr_size(void **arr, uint size);
static char					**create_str_tab(char **tab, int number_of_words, char *argv);
static void 				print_rev_tab(int number_of_words, char **tab);


//-----------------------MAIN----------------------------


int	main(int argc, char **argv)
{
	char	**tab;
	char	**rev_tab;
	int		number_of_words;

	if (argc != 2)
		return (putstring("\n"));
	number_of_words = my_wordcounter(argv[1]);
	tab = malloc(sizeof(char *) * number_of_words);
	tab = create_str_tab(tab, number_of_words, argv[1]);
	print_rev_tab(number_of_words, tab);
	ft_free_arr_size((void **)tab, number_of_words);
}


//---------------------------------AUXILIARY-------------------------------------


static inline char	**create_str_tab(char **tab, int number_of_words, char *argv)
{
	int		i;
	int		j;
	char	*word;
	int		wordlen;

	i = -1;
	j = -1;
	while (++i < number_of_words)
	{
		word = (char *)get_word_by_index(i, argv, number_of_words);
		wordlen = my_strlen(word);
		tab[i] = malloc(sizeof(char) * wordlen + 1);
		while (++j < wordlen && word[j])
			tab[i][j] = word[j];
		tab[i][wordlen] = '\0';
		j = -1;
	}
	return (tab);
}

static inline void 				print_rev_tab(int number_of_words, char **tab)
{
    while (number_of_words-- > 0)
	{
	  putstring(tab[number_of_words]);
	  write(1, " ", 1);
	}
	write(1, "\n", 1);
}

static inline int	is_whitespace(char c)
{
	int					i;
	static const char	whitespace[3] = {' ', '\t', '\0'};
	i = 3;
	while (--i != -1)
		if (c == whitespace[i])
			return (1);
	return (0);
}

static inline int	putstring(char *s)
{
	if (!s)
		return (0);
	while (*s)
		write(1, s++, 1);
	return (1);
}

static inline int	my_strlen(char *s)
{
	int	len;

	len = 0;
	while ((!is_whitespace(*s) && s++))
		len++;
	return (len);
}

static inline int	my_wordcounter(char *s)
{
	int	words;
	int	i;

	words = 0;
	i = -1;
	while (*s++)
		if (is_whitespace(*s))
			words++;
	return (words);
}

static inline char	*get_word_by_index(int index, char *s, int number_of_words)
{
	int			white;
	int			i;
	char		*word;
	char		*adresses[number_of_words];

	white = 0;
	i = -1;
	if (index == 0)
		return (s);
	while (*s++)
		if (is_whitespace(*s))
		{
			adresses[white] = s + 1;
			white++;
			if (white == index)
				return (adresses[white - 1]);
		}
	return (0);
}

static inline void	ft_free_arr_size(void **arr, uint size)
{
	uint	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
