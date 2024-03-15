/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partitioning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:59:23 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/15 20:44:00 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_len_stack(t_stack *stack)
{
	size_t	len;
	t_stack	*end;

	len = 1;
	end = stack->prev;
	while (stack != end)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

char	ft_partnew_front(t_partition **part, size_t n)
{
	t_partition	*new;

	new = malloc(sizeof(t_partition));
	if (!new)
		return (1);
	new->len = n;
	new->next = *part;
	*part = new;
	return (0);
}

void	ft_pop_part(t_partition **part)
{
	t_partition	*tmp;

	tmp = (*part)->next;
	free(*part);
	*part = tmp;
}

char	ft_partition(t_partition **part_dst, t_partition **part_src)
{
	size_t	len;

	len = (*part_src)->len;
	(*part_src)->len = (len + 1) / 2;
	if (ft_partnew_front(part_dst, len / 2))
		return (1);
	return (0);
}
