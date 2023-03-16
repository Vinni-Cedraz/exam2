

static void			swap_it(int *a, int *b);

static int			pair_not_sorted(int a, int b);



//-------------------MAIN---------------------------


void	my_sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;

	i = -1;
	while (++i < size) {
		if (pair_not_sorted(tab[i], tab[i + 1]))
			swap_it(&tab[i], &tab[i + 1]);
		size--;
	}
}


//---------------------AUXILIARY--------------------


static inline int	pair_not_sorted(int a, int b)
{
	return (a > b);
}

static inline void	swap_it(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// trash recursive version

// static int			tab_not_sorted(int *tab, int size);

// void	my_sort_int_tab(int *tab, unsigned int size)
// {
// 	unsigned int	i;
//
// 	i = -1;
// 	while (++i < size)
// 		if (pair_not_sorted(tab[i], tab[i + 1]))
// 			swap_it(&tab[i], &tab[i + 1]);
// 	if (tab_not_sorted(tab, size))
// 		my_sort_int_tab(tab, size);
// }
//
// static inline int	tab_not_sorted(int *tab, int size)
// {
// 	int	i;
//
// 	i = -1;
// 	while (++i < size)
// 		if (pair_not_sorted(tab[i], tab[i + 1]))
// 			return (1);
// 	return (0);
// }
