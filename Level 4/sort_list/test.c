#include "my_sort_list.c"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void				print_number(int number);
static size_t			aux_putchar(char c);
static void				ft_lstprint(t_list **lst);
static t_list			*ft_lstnew(int data);
static void				ft_lstadd_back(t_list **lst, t_list *new);

int	main(void)
{
	t_list	*node;
	int		i;

	i = 99999;
	node = ft_lstnew(i);
	while (--i)
		ft_lstadd_back(&node, ft_lstnew(i));
	my_sort_list(node, cmp_ascending);
	ft_lstprint(&node);
	my_sort_list(node, cmp_descending);
	ft_lstprint(&node);
}

static inline void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;
}

static inline t_list	*ft_lstnew(int data)
{
	t_list	*node;

	node = malloc(sizeof(*node));
	node->data = data;
	node->next = NULL;
	return (node);
}

static inline void	print_number(int number)
{
	int					digits[10];
	int					i;
	static const char	str[10] = {"0123456789"};

	i = 0;
	while (number > 0)
	{
		digits[i++] = number % 10;
		number /= 10;
	}
	while (i > 0)
	{
		i--;
		write(1, &str[digits[i]], 1);
	}
}

static inline size_t	aux_putchar(char c)
{
	return (write(1, &c, 1));
}

static inline void	ft_lstprint(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		print_number(tmp->data);
		aux_putchar('-');
		aux_putchar('>');
		aux_putchar('\n');
		tmp = tmp->next;
	}
}
