/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:21:31 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/15 19:55:50 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_partition(t_stack **element1, t_stack **element2)
{
	t_stack	*tmp;

	tmp = *element1;
	*element1 = *element2;
	*element2 = tmp;
}

static t_stack	**ft_median_partition(t_stack **stack, size_t len)
{
	size_t	i;
	t_stack	*current;
	t_stack	**partition;

	partition = malloc((len + 1) * sizeof(t_stack *));
	if (!partition)
		return (NULL);
	partition[len] = NULL;
	i = 0;
	current = *stack;
	while (i < len)
	{
		partition[i] = current;
		current = current->next;
		i++;
	}
	return (partition);
}

t_stack	*ft_median_quickselect(t_stack **partition, size_t len)
{
	size_t	sorted;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	end = len - 1;
	while (end - start > 0)
	{
		i = start;
		sorted = start;
		while (i < end)
		{
			if (partition[i]->n < partition[end]->n)
				ft_swap_partition(&partition[i], &partition[sorted++]);
			i++;
		}
		ft_swap_partition(&partition[end], &partition[sorted]);
		if (2 * sorted < len)
			start = sorted;
		else
			end = sorted - 1;
		/*printf("Partition :\n");
		for (size_t j=start;j<=end;j++)
			printf("n=%d\n",partition[j]->n);
		printf("start=%zu   end=%zu   diff=%zu\n",start,end,end-start);*/
	}
	return (partition[end]);
}

t_stack	*ft_median(t_stack **stack, t_partition **part)
{
	t_stack	**partition;
	t_stack	*median;

	//printf("len=%zu\n",(*part)->len);
	//printf("Stack :\n");
	//pstk(stack);
	partition = ft_median_partition(stack, (*part)->len);
	if (!partition)
		return (NULL);
	//printf("Partition start :\n");
	//for (size_t j=0;partition[j];j++)
	//	printf("n=%d\n",partition[j]->n);
	median = ft_median_quickselect(partition, (*part)->len);
	free(partition);
	return (median);
}
