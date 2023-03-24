#include "my_list_remove_if.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	print_list(t_list **begin_list)
{
	t_list *cur = *begin_list;
	while (cur != 0)
	{
		printf("%s\n", (char *)cur->data);
		cur = cur->next;
	}
}

int ft_strcmp(void *s1, void *s2)
{
	int i = 0;
	char *str1 = (char *)s1;
	char *str2 = (char *)s2;
	
	while(str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	ft_lstfree(t_list **list)
{
	t_list *tmp;

	tmp = *list;
	if (list == NULL)
		return ;
	while (tmp)
	{
		*list = tmp->next;
		free(tmp);
		tmp = *list;
	}
}

int		main(void)
{
	char straa[] = "String aa";
	t_list *aa = malloc(sizeof(t_list));
	aa->next = 0;
	aa->data = straa;
	char strbb[] = "String bb";
	t_list *bb = malloc(sizeof(t_list));
	bb->next = 0;
	bb->data = strbb;
	char strcc[] = "String cc";
	t_list *cc = malloc(sizeof(t_list));
	cc->next = 0;
	cc->data = strcc;
	char strdd[] = "String dd";
	t_list *dd = malloc(sizeof(t_list));
	dd->next = 0;
	dd->data = strdd;
	char stra[] = "String aa";
	t_list *a = malloc(sizeof(t_list));
	a->next = 0;
	a->data = stra;
	aa->next = bb;
	bb->next = cc;
	cc->next = dd;
	dd->next = a;
	t_list **begin_list = &aa;
	print_list(begin_list);
	printf("----------\n");
	my_list_remove_if(begin_list, straa, ft_strcmp);
	print_list(begin_list);
	ft_lstfree(begin_list);
}
