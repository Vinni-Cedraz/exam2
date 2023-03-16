#include "sort_list.list.h"
#include <unistd.h>

t_list				*my_sort_list(t_list *lst, int (*cmp)(int, int));
static void			sort_neighbors(t_list*, t_list*, int (*)(int, int));
static void			data_swap(int *a, int *b);

//------------------------MAIN--------------------------


t_list	*my_sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*next;
	t_list	*head;

	head = next = lst;
	while (head)
	{
		next = head->next;
		sort_neighbors(head, next, cmp);
		head = head->next;
	}
	return (lst);
}


//------------------------------------AUXILIARY-------------------------------------


static inline void	sort_neighbors(t_list *head, t_list *next, int (*cmp)(int, int))
{
	while (next)
	{
		if (!cmp(head->data, next->data))
			data_swap(&head->data, &next->data);
		next = next->next;
	}
}

static inline void	data_swap(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}
