/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 03:06:57 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/08 13:28:56 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	rr(t_stack **stack1, t_stack **stack2, char *instruction,
	t_list **lst_instruction)
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
	if (rotated && ft_lstnew_back(lst_instruction, (void *)instruction))
		return (1);
	return (0);
}

char	rrx(t_stack **stack, char *instruction, t_list **lst_instruction)
{
	if (*stack)
	{
		if (ft_lstnew_back(lst_instruction, (void *)instruction))
			return (1);
		*stack = (*stack)->prev;
	}
	return (0);
}

char	rrr(t_stack **stack1, t_stack **stack2, char *instruction,
	t_list **lst_instruction)
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
	if (rotated && ft_lstnew_back(lst_instruction, (void *)instruction))
		return (1);
	return (0);
}
