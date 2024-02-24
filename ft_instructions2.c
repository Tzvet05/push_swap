/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 03:06:57 by ttrave            #+#    #+#             */
/*   Updated: 2024/02/08 20:48:26 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx(t_stack **stack, char *instruction)
{
	if (*stack)
	{
		ft_putstr_fd(instruction, STDOUT);
		*stack = (*stack)->next;
	}
}

void	rr(t_stack **stack1, t_stack **stack2, char *instruction)
{
	char	rotated;

	rotated = 0;
	if (*stack1)
	{
		*stack1 = (*stack1)->next;
		rotated = 1;
	}
	if (*stack2)
	{
		*stack2 = (*stack2)->next;
		rotated = 1;
	}
	if (rotated)
		ft_putstr_fd(instruction, STDOUT);
}

void	rrx(t_stack **stack, char *instruction)
{
	if (*stack)
	{
		ft_putstr_fd(instruction, STDOUT);
		*stack = (*stack)->prev;
	}
}

void	rrr(t_stack **stack1, t_stack **stack2, char *instruction)
{
	char	rotated;

	rotated = 0;
	if (*stack1)
	{
		*stack1 = (*stack1)->prev;
		rotated = 1;
	}
	if (*stack2)
	{
		*stack2 = (*stack2)->prev;
		rotated = 1;
	}
	if (rotated)
		ft_putstr_fd(instruction, STDOUT);
}
