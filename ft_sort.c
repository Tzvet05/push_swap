/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:32:18 by ttrave            #+#    #+#             */
/*   Updated: 2024/02/24 16:23:18 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_presort_a(t_storage *data)
{
	size_t	i;
	t_stack	*median;

	while ((*(data->part_a))->len > 3)
	{
		i = 0;
		median = ft_median(data->a, data->part_a);
		if (!median)
			return (1);
		while (i < (*(data->part_a))->len)
		{
			if ((*(data->a))->n <= median->n)
			{
				if (instr(PB, data->a, data->b))
					return (1);
			}
			else if (instr(RA, data->a, data->b))
					return (1);
			i++;
		}
		if (ft_partition(data->part_b, data->part_a))
			return (1);
	}
	return (ft_sort_partition_a(data));
}
/*
char	ft_sort_a(t_storage *data)
{
	while ()
	{
		
	}
	return (0);
}*/










/*
pushes and sorts the elements from data->a to data->pivot->content from stack data->a to stack data->b, and pops *(data->pivot)

char	ft_quicksort_a_to_b(t_storage *data, char (*cmp)(int, int))
{
	t_list	*pivot_end;

	pivot_end = *(data->part_a);
	while (ft_len_partition(*(data->a), pivot_end) > 3)
	{
	if (ft_len_partition(*(data->a), *(data->pivot)) <= 3)
		{
			if (ft_push_sort_a_to_b(data))
				return (1);
			continue ;
		}
		if (ft_median(data->a, data->pivot))//comment savoir si ra ou rra ?
			return (1);
		if (ft_partition(data, cmp))
			return (1);
	}
	if (ft_push_sort_a_to_b(data))
		return (1);
	return (0);
}*/
