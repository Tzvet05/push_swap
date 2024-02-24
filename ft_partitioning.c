/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_partitioning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:59:23 by ttrave            #+#    #+#             */
/*   Updated: 2024/02/24 12:39:29 by ttrave           ###   ########.fr       */
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

char	ft_partition(t_partition **part_dst, t_partition **part_src)
{
	size_t	len;

	len = (*part_src)->len;
	(*part_src)->len = len / 2;
	if (ft_partnew_front(part_dst, len / 2 + len % 2))
		return (1);
	return (0);
}
