/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 03:06:57 by ttrave            #+#    #+#             */
/*   Updated: 2024/02/23 13:31:44 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sx(t_stack **stack, char *instruction)
{
	int	tmp;

	if (!*stack || (*stack)->next == *stack)
		return ;
	ft_putstr_fd(instruction, STDOUT);
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

static void	ss(t_stack **stack1, t_stack **stack2, char *instruction)
{
	int		tmp;
	char	swapped;

	swapped = 0;
	if (*stack1 && (*stack1)->next != *stack1)
	{
		tmp = (*stack1)->n;
		(*stack1)->n = (*stack1)->next->n;
		(*stack1)->next->n = tmp;
		swapped = 1;
	}
	if (*stack2 && (*stack2)->next != *stack2)
	{
		tmp = (*stack2)->n;
		(*stack2)->n = (*stack2)->next->n;
		(*stack2)->next->n = tmp;
		swapped = 1;
	}
	if (swapped)
		ft_putstr_fd(instruction, STDOUT);
}

static void	px(t_stack **stack1, t_stack **stack2, char *instruction)
{
	t_stack	*push;

	if (!*stack1)
		return ;
	ft_putstr_fd(instruction, STDOUT);
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

char	instr(char *instruction, t_stack **a, t_stack **b)
{
	if (ft_strcmp(instruction, SA))
		sx(a, instruction);
	else if (ft_strcmp(instruction, SB))
		sx(b, instruction);
	else if (ft_strcmp(instruction, SS))
		ss(a, b, instruction);
	else if (ft_strcmp(instruction, PA))
		px(b, a, instruction);
	else if (ft_strcmp(instruction, PB))
		px(a, b, instruction);
	else if (ft_strcmp(instruction, RA))
		rx(a, instruction);
	else if (ft_strcmp(instruction, RB))
		rx(b, instruction);
	else if (ft_strcmp(instruction, RR))
		rr(a, b, instruction);
	else if (ft_strcmp(instruction, RRA))
		rrx(a, instruction);
	else if (ft_strcmp(instruction, RRB))
		rrx(b, instruction);
	else
		rrr(a, b, instruction);
	return (0);
}
