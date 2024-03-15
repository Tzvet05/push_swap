/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:32:18 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/15 21:24:56 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	ft_push_b(t_storage *data, int pivot)
{
	size_t	offset;
	size_t	to_push;

	offset = 0;
	to_push = (*(data->part_a))->len / 2;
	while (to_push)
	{
		if ((*(data->a))->n < pivot
			|| (!((*(data->part_a))->len % 2) && (*(data->a))->n == pivot))
		{
			if (instr(PB, data->a, data->b, data->instructions))
				return (1);
			to_push--;
			continue ;
		}
		if (instr(RA, data->a, data->b, data->instructions))
			return (1);
		offset++;
	}
	while (offset)
	{
		if (instr(RRA, data->a, data->b, data->instructions))
			return (1);
		offset--;
	}
	return (0);
}

char	ft_quicksort_b(t_storage *data)
{
	t_stack	*pivot;

	while ((*(data->part_a))->len > 3)
	{
		pivot = ft_median(data->a, data->part_a);
		if (!pivot)
			return (1);
		if (ft_push_b(data, pivot->n)
			|| ft_partition(data->part_b, data->part_a))
			return (1);
	}
	if (ft_sort_multi_part_a(data))
		return (1);
	return (0);
}

static char	ft_cycle_part_b(t_storage *data, size_t offset)
{
	if (!(*(data->part_b))->next)
		return (0);
	while (offset)
	{
		if (instr(RRB, data->a, data->b, data->instructions))
			return (1);
		offset--;
	}
	return (0);
}

static char	ft_push_a(t_storage *data, int pivot)
{
	size_t	offset;
	size_t	to_push;

	offset = 0;
	to_push = (*(data->part_b))->len / 2;
	while (to_push)
	{
		if ((*(data->b))->n > pivot)
		{
			if (instr(PA, data->a, data->b, data->instructions))
				return (1);
			to_push--;
			continue ;
		}
		if (instr(RB, data->a, data->b, data->instructions))
			return (1);
		offset++;
	}
	if (ft_cycle_part_b(data, offset))
		return (1);
	return (0);
}

char	ft_quicksort_a(t_storage *data)
{
	t_stack	*pivot;
	t_stack	*next_pivot;

	if ((*(data->part_b))->len > 3)
	{
		pivot = ft_median(data->b, data->part_b);
		if (!pivot)
			return (1);
		//next_pivot = ft_next_median(data->b, data->part_b, pivot->n, 'A');
		//if (!next_pivot)
		//	return (0);
		if (ft_push_a(data, pivot->n)
			|| ft_partition(data->part_a, data->part_b))
			return (1);
	}
	else if (ft_push_sort_partition_a(data))
		return (1);
	return (0);
}
