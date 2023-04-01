typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

static  int cmp_ascending(int a, int b)
{
	return (a <= b);
}

static  int cmp_descending(int a, int b)
{
	return (a >= b);
}

t_list	*my_sort_list(t_list *lst, int (*cmp)(int, int));
