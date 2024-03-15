/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 03:06:57 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/14 17:00:35 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	sx(t_stack **stack, char *instruction, t_list **lst_instruction)
{
	int	tmp;

	if (!*stack || (*stack)->next == *stack)
		return (0);
	if (ft_lstnew_back(lst_instruction, (void *)instruction))
		return (1);
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
	return (0);
}

static char	ss(t_stack **stack1, t_stack **stack2, char *instruction,
		t_list **lst_instruction)
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
	if (swapped && ft_lstnew_back(lst_instruction, (void *)instruction))
		return (1);
	return (0);
}

static char	px(t_stack **stack1, t_stack **stack2, char *instruction,
		t_list **lst_instruction)
{
	t_stack	*push;

	if (!*stack1)
		return (0);
	if (ft_lstnew_back(lst_instruction, (void *)instruction))
		return (1);
	push = *stack1;
	push->prev->next = push->next;
	push->next->prev = push->prev;
	*stack1 = NULL;
	if (push->next != push)
		*stack1 = push->next;
	if (!*stack2)
	{
		push->next = push;
		push->prev = push;
		*stack2 = push;
		return (0);
	}
	push->prev = (*stack2)->prev;
	push->next = *stack2;
	(*stack2)->prev->next = push;
	(*stack2)->prev = push;
	*stack2 = push;
	return (0);
}

static char	rx(t_stack **stack, char *instruction, t_list **lst_instruction)
{
	if (*stack)
	{
		if (ft_lstnew_back(lst_instruction, (void *)instruction))
			return (1);
		*stack = (*stack)->next;
	}
	return (0);
}

char	instr(char *instruction, t_stack **a, t_stack **b,
	t_list **lst_instruction)
{
	if (ft_strcmp(instruction, SA))
		return (sx(a, instruction, lst_instruction));
	if (ft_strcmp(instruction, SB))
		return (sx(b, instruction, lst_instruction));
	if (ft_strcmp(instruction, SS))
		return (ss(a, b, instruction, lst_instruction));
	if (ft_strcmp(instruction, PA))
		return (px(b, a, instruction, lst_instruction));
	if (ft_strcmp(instruction, PB))
		return (px(a, b, instruction, lst_instruction));
	if (ft_strcmp(instruction, RA))
		return (rx(a, instruction, lst_instruction));
	if (ft_strcmp(instruction, RB))
		return (rx(b, instruction, lst_instruction));
	if (ft_strcmp(instruction, RR))
		return (rr(a, b, instruction, lst_instruction));
	if (ft_strcmp(instruction, RRA))
		return (rrx(a, instruction, lst_instruction));
	if (ft_strcmp(instruction, RRB))
		return (rrx(b, instruction, lst_instruction));
	return (rrr(a, b, instruction, lst_instruction));
}
