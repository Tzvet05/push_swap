/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 03:06:57 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/09 15:58:57 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rr(t_stack **stack1, t_stack **stack2)
{
	if (*stack1)
		*stack1 = (*stack1)->next;
	if (*stack2)
		*stack2 = (*stack2)->next;
}

void	rrx(t_stack **stack)
{
	if (*stack)
		*stack = (*stack)->prev;
}

void	rrr(t_stack **stack1, t_stack **stack2)
{
	if (*stack1)
		*stack1 = (*stack1)->prev;
	if (*stack2)
		*stack2 = (*stack2)->prev;
}
