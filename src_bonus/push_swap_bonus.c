/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:05:01 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/09 18:45:23 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	ft_check_sorted(t_stack **stack)
{
	t_stack	*current;
	int		nbr;

	current = *stack;
	if (current->next == current)
		return (1);
	nbr = current->n;
	current = current->next;
	while (current != *stack)
	{
		if (nbr > current->n)
			return (0);
		nbr = current->n;
		current = current->next;
	}
	return (1);
}

static char	ft_check_instruction(char *instr)
{
	size_t	i;

	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(instr, "sa\n") || ft_strcmp(instr, "sb\n")
			|| ft_strcmp(instr, "ss\n") || ft_strcmp(instr, "pa\n")
			|| ft_strcmp(instr, "pb\n") || ft_strcmp(instr, "ra\n")
			|| ft_strcmp(instr, "rb\n") || ft_strcmp(instr, "rr\n")
			|| ft_strcmp(instr, "rra\n") || ft_strcmp(instr, "rrb\n")
			|| ft_strcmp(instr, "rrr\n"))
			return (0);
		i++;
	}
	return (1);
}

static char	ft_execute_sequence(t_stack **a, t_stack **b)
{
	char	*line;
	char	error;

	error = 0;
	line = get_next_line(0, 1, &error);
	if (error)
		return (1);
	while (line)
	{
		if (ft_check_instruction(line))
		{
			free(line);
			return (1);
		}
		instr(line, a, b);
		free(line);
		line = get_next_line(0, 1, &error);
		if (error)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		exit(0);
	stack_a = NULL;
	stack_b = NULL;
	ft_init_stack(&argv[1], &stack_a);
	if (ft_execute_sequence(&stack_a, &stack_b))
	{
		ft_free_stack(&stack_a);
		ft_free_stack(&stack_b);
		ft_puterr();
		return (1);
	}
	if (ft_check_sorted(&stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	exit(0);
}
