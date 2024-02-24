//retirer prototype du header !!

#include "push_swap.h"

void	ppart(t_partition **part)
{
	t_partition	*tmp;

	if (!*part)
	{
		printf("No partitions in stack\n");
		return ;
	}
	printf("From top to bottom\n");
	tmp = *part;
	while (tmp)
	{
		printf("len=%zu\n",tmp->len);
		tmp = tmp->next;
	}
}

void	plst(t_list **lst)
{
	t_list	*node;
	t_stack	*tmp;
	size_t	i;

	i = 0;
	node = *lst;
	if (!node)
	{
		printf("Linked list is empty.\n");
		return ;
	}
	printf("From top to bottom :\n");
	while (node)
	{
		tmp = node->content;
		printf("Pivot %zu=%d\n",i,tmp->n);
		node = node->next;
		i++;
	}
}

void	pstk(t_stack **lst)
{
	t_stack	*node;

	node = *lst;
	if (!node)
	{
		printf("Stack is empty.\n");
		return ;
	}
	printf("n=%d\n", node->n);
	node = node->next;
	while (node != *lst)
	{
		printf("n=%d\n", node->n);
		fflush(stdout);
		node = node->next;
	}
}
