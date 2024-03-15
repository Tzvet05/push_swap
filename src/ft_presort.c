/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:39:21 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/15 21:21:43 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	ft_push_presort_a(t_storage *data, int pivot)
{
	size_t	to_push;

	to_push = (*(data->part_a))->len / 2;
	while (to_push)
	{
		if ((*(data->a))->n < pivot
			|| (!((*(data->part_a))->len % 2) && (*(data->a))->n == pivot))
		{
			if (instr(PB, data->a, data->b, data->instructions))
				return (1);
			to_push--;
		}
		else if (instr(RA, data->a, data->b, data->instructions))
			return (1);
	}
	return (0);
}

char	ft_presort_a(t_storage *data)
{
	t_stack	*median;

	while ((*(data->part_a))->len > 3)
	{
		median = ft_median(data->a, data->part_a);
		if (!median)
			return (1);
		if (ft_push_presort_a(data, median->n)
			|| ft_partition(data->part_b, data->part_a))
			return (1);
	}
	return (ft_sort_single_part_a(data));
}
