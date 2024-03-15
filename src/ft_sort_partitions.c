/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_partitions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:06:56 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/14 16:46:51 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_sort_single_part_a(t_storage *data)
{
	t_stack	*stack;

	stack = *(data->a);
	if ((*(data->part_a))->len < LEN_PARTITION)
	{
		if (stack->n > stack->next->n
			&& instr(SA, data->a, data->b, data->instructions))
			return (1);
		ft_pop_part(data->part_a);
		return (0);
	}
	ft_pop_part(data->part_a);
	if (stack->n > stack->next->n && stack->n < stack->prev->n)
		return (instr(SA, data->a, data->b, data->instructions));
	if (stack->prev->n > stack->next->n && stack->n > stack->prev->n)
		return (instr(RA, data->a, data->b, data->instructions));
	if (stack->n < stack->next->n && stack->n > stack->prev->n)
		return (instr(RRA, data->a, data->b, data->instructions));
	if (stack->n > stack->next->n && stack->next->n > stack->prev->n)
		return (instr(SA, data->a, data->b, data->instructions)
			|| instr(RRA, data->a, data->b, data->instructions));
	if (stack->n < stack->prev->n && stack->next->n > stack->prev->n)
		return (instr(RRA, data->a, data->b, data->instructions)
			|| instr(SA, data->a, data->b, data->instructions));
	return (0);
}

char	ft_sort_multi_part_a(t_storage *data)
{
	t_stack	*stack;

	stack = *(data->a);
	if ((*(data->part_a))->len < LEN_PARTITION)
	{
		if (stack->n > stack->next->n
			&& instr(SA, data->a, data->b, data->instructions))
			return (1);
		ft_pop_part(data->part_a);
		return (0);
	}
	if (stack->n > stack->next->n
		&& instr(SA, data->a, data->b, data->instructions))
		return (1);
	if (stack->next->n > stack->next->next->n
		&& (instr(RA, data->a, data->b, data->instructions)
			|| instr(SA, data->a, data->b, data->instructions)
			|| instr(RRA, data->a, data->b, data->instructions)))
		return (1);
	if (stack->n > stack->next->n
		&& instr(SA, data->a, data->b, data->instructions))
		return (1);
	ft_pop_part(data->part_a);
	return (0);
}

char	ft_push_sort_partition_a(t_storage *data)
{
	size_t	len_b;
	t_stack	**a;
	t_stack	**b;

	a = data->a;
	b = data->b;
	len_b = (*(data->part_b))->len;
	if (len_b > 2 && (*b)->n < (*b)->next->n
		&& instr(SB, a, b, data->instructions))
		return (1);
	if (len_b > 2 && instr(PA, a, b, data->instructions))
		return (1);
	if (len_b > 1 && (*b)->n < (*b)->next->n
		&& instr(SB, a, b, data->instructions))
		return (1);
	if (len_b > 1 && instr(PA, a, b, data->instructions))
		return (1);
	if (len_b > 2 && (*a)->n > (*a)->next->n
		&& instr(SA, a, b, data->instructions))
		return (1);
	if (instr(PA, a, b, data->instructions))
		return (1);
	ft_pop_part(data->part_b);
	return (0);
}
