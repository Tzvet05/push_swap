/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti_instr_buff.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:30:22 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/14 16:58:41 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_print_instructions(t_list **instructions)
{
	t_list	*current;

	current = *instructions;
	while (current)
	{
		write(1, current->content, ft_strlen(current->content));
		current = current->next;
	}
}

static void	ft_opti_replace(t_list **top, char *instruction, size_t replace_len,
		size_t total_len)
{
	t_list	*current;
	t_list	*previous;

	current = *top;
	total_len -= replace_len;
	while (total_len)
	{
		previous = current;
		current = current->next;
		free(previous);
		total_len--;
	}
	*top = current;
	while (replace_len)
	{
		current->content = instruction;
		current = current->next;
		replace_len--;
	}
}

static void	ft_opti_merge_instr(t_list **top, char *instr1, char *instr2,
		char *instr_merge)
{
	t_list	*current;

	current = *top;
	if ((ft_strcmp(current->content, instr1)
			&& ft_strcmp(current->next->content, instr2))
		|| (ft_strcmp(current->content, instr2)
			&& ft_strcmp(current->next->content, instr1)))
		ft_opti_replace(top, instr_merge, 1, 2);
}

static void	ft_opti_canceling_instr(t_list **top, char *instr1, char *instr2)
{
	t_list	*current;
	size_t	n1;
	size_t	n2;

	n1 = 0;
	n2 = 0;
	current = *top;
	while (current && (ft_strcmp(current->content, instr1)
			|| ft_strcmp(current->content, instr2)))
	{
		if (ft_strcmp(current->content, instr1))
			n1++;
		else
			n2++;
		current = current->next;
	}
	if (!n1 || !n2)
		return ;
	if (n1 > n2)
		ft_opti_replace(top, instr1, n1 - n2, n1 + n2);
	else if (n1 < n2)
		ft_opti_replace(top, instr2, n2 - n1, n1 + n2);
	else
		ft_opti_replace(top, NULL, 0, n1 + n2);
}

static void	ft_opti_end_part(t_list **top)
{
	t_list	*current;

	current = *top;
	if (ft_strcmp(current->content, RA)
		&& ft_strcmp(current->next->content, PB)
		&& ft_strcmp(current->next->next->content, RRA))
	{
		current->content = SA;
		ft_opti_replace(&(current->next), PB, 1, 2);
	}
	else if (ft_strcmp(current->content, RB)
		&& ft_strcmp(current->next->content, PA)
		&& ft_strcmp(current->next->next->content, RRB))
	{
		current->content = SB;
		ft_opti_replace(&(current->next), PA, 1, 2);
	}
}

void	ft_opti_instructions(t_list **instructions)
{
	t_list	**top;
	char	iterations;

	iterations = 2;
	while (iterations--)
	{
		top = instructions;
		while (*top)
		{
			if (*top && (*top)->next)
				ft_opti_merge_instr(top, SA, SB, SS);
			if (*top && (*top)->next)
				ft_opti_merge_instr(top, RA, RB, RR);
			if (*top && (*top)->next)
				ft_opti_merge_instr(top, RRA, RRB, RRR);
			if (*top && (*top)->next && (*top)->next->next)
				ft_opti_end_part(top);
			ft_opti_canceling_instr(top, PA, PB);
			ft_opti_canceling_instr(top, RB, RRB);
			ft_opti_canceling_instr(top, RA, RRA);
			if (*top)
				top = &((*top)->next);
		}
	}
	ft_print_instructions(instructions);
}
