/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 03:06:57 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/09 15:58:48 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	sx(t_stack **stack)
{
	int	tmp;

	if (!*stack || (*stack)->next == *stack)
		return ;
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

static void	ss(t_stack **stack1, t_stack **stack2)
{
	int		tmp;

	if (*stack1 && (*stack1)->next != *stack1)
	{
		tmp = (*stack1)->n;
		(*stack1)->n = (*stack1)->next->n;
		(*stack1)->next->n = tmp;
	}
	if (*stack2 && (*stack2)->next != *stack2)
	{
		tmp = (*stack2)->n;
		(*stack2)->n = (*stack2)->next->n;
		(*stack2)->next->n = tmp;
	}
}

static void	px(t_stack **stack1, t_stack **stack2)
{
	t_stack	*push;

	if (!*stack1)
		return ;
	push = *stack1;
	push->prev->next = push->next;
	push->next->prev = push->prev;
	if (push->next == push)
		*stack1 = NULL;
	else
		*stack1 = push->next;
	if (!*stack2)
	{
		push->next = push;
		push->prev = push;
		*stack2 = push;
		return ;
	}
	push->prev = (*stack2)->prev;
	push->next = *stack2;
	(*stack2)->prev->next = push;
	(*stack2)->prev = push;
	*stack2 = push;
}

static void	rx(t_stack **stack)
{
	if (*stack)
		*stack = (*stack)->next;
}

void	instr(char *instruction, t_stack **a, t_stack **b)
{
	if (ft_strcmp(instruction, SA))
		sx(a);
	else if (ft_strcmp(instruction, SB))
		sx(b);
	else if (ft_strcmp(instruction, SS))
		ss(a, b);
	else if (ft_strcmp(instruction, PA))
		px(b, a);
	else if (ft_strcmp(instruction, PB))
		px(a, b);
	else if (ft_strcmp(instruction, RA))
		rx(a);
	else if (ft_strcmp(instruction, RB))
		rx(b);
	else if (ft_strcmp(instruction, RR))
		rr(a, b);
	else if (ft_strcmp(instruction, RRA))
		rrx(a);
	else if (ft_strcmp(instruction, RRB))
		rrx(b);
	else
		rrr(a, b);
}
