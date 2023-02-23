#include "ft_list.h"

static void remove_node(t_list **, t_list*);

void my_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void*, void*))
{
	t_list *tmp;
	
	tmp = *begin_list;
	if (!(*cmp)(tmp->data, data_ref))
		remove_node(begin_list, tmp);
	
}
