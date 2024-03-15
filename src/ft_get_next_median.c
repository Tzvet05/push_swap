/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_median.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:44:40 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/15 19:55:37 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	ft_greater(int n1, int n2)
{
	return (n1 > n2);
}

static char	ft_lesser(int n1, int n2)
{
	return (n1 <= n2);
}

static t_stack	**ft_next_median_partition(t_stack **stack, size_t len, int median, char (*cmp)(int, int))
{
	t_stack	**partition;
	t_stack	*current;
	size_t	i;

	partition = malloc((len + 1) * sizeof(t_stack *));
	if (!partition)
		return (NULL);
	partition[len] = NULL;
	current = *stack;
	i = 0;
	while (i < len)
	{
		if ((*cmp)(current->n, median))
		{
			partition[i] = current;
			i++;
		}
		current = current->next;
	}
	return (partition);
}

t_stack	*ft_next_median(t_stack **stack, t_partition **part, int median, char stack_dest)
{
	t_stack	**partition;
	t_stack	*next_median;
	size_t	len;

	printf("Stack :\n");
	pstk(stack);
	if (stack_dest == 'A')
		len = ((*part)->len + 1) / 2;
	else
		len = ((*part)->len) / 2;
	printf("len=%zu\n",len);
	if (stack_dest == 'A')
		partition = ft_next_median_partition(stack, len, median, &ft_greater);
	else
		partition = ft_next_median_partition(stack, len, median, &ft_lesser);
	if (!partition)
		return (NULL);
	printf("Partition :\n");
	for (size_t j = 0; j < len; j++)
		printf("n=%d\n",partition[j]->n);
	next_median = ft_median_quickselect(partition, len);
	free(partition);
	return (next_median);
}
