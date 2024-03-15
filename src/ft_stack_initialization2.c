/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_initialization2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 02:28:51 by ttrave            #+#    #+#             */
/*   Updated: 2024/02/01 02:29:03 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_link_stack(t_stack **stack)
{
	t_stack	*top;
	t_stack	*node;

	if (!*stack)
		return ;
	top = *stack;
	node = *stack;
	while (node->next)
		node = node->next;
	node->next = top;
	top->prev = node;
}
