/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_partitions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:06:56 by ttrave            #+#    #+#             */
/*   Updated: 2024/02/24 16:29:54 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_sort_partition_a(t_storage *data)
{
	size_t	len;
	t_stack	*stack_a;

	len = (*(data->part_a))->len;
	if (len < 2)
		return (0);
	stack_a = *(data->a);
	if (len < 3 && stack_a->n > stack_a->next->n)
	{
		if (instr(SA, data->a, data->b))
			return (1);
		return (0);
	}
	if (stack_a->n > stack_a->next->n && instr(SA, data->a, data->b))
		return (1);
	if (stack_a->next->n > stack_a->next->next->n
		&& (instr(RA, data->a, data->b)
			|| instr(SA, data->a, data->b)
			|| instr(RRA, data->a, data->b)))
		return (1);
	if (stack_a->n > stack_a->next->n && instr(SA, data->a, data->b))
		return (1);
	return (0);
}
