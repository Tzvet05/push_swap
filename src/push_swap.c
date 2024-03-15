/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:05:01 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/15 21:23:27 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static char	ft_sort_stack(t_storage *data)
{
	if (ft_presort_a(data))
	{
		ft_free_all(data);
		return (1);
	}
	while (*(data->part_a) || *(data->part_b))
	{
		if (*(data->part_a) && ft_quicksort_b(data))
			return (1);
		if (ft_quicksort_a(data))
			return (1);
	}
	return (0);
}

static void	ft_push_swap(t_storage data)
{
	t_list		*instructions;
	t_stack		*stack_b;
	t_partition	*part_b;

	stack_b = NULL;
	data.b = &stack_b;
	part_b = NULL;
	data.part_b = &part_b;
	instructions = NULL;
	data.instructions = &instructions;
	if (ft_sort_stack(&data))
		ft_puterr();
	else
		ft_opti_instructions(data.instructions);
	ft_lstclear(data.instructions, NULL);
	ft_free_part(data.part_a);
	ft_free_part(data.part_b);
	ft_free_stack(data.a);
}

int	main(int argc, char **argv)
{
	t_storage	data;
	t_stack		*stack_a;
	t_partition	*part_a;

	if (argc < 2)
		exit(0);
	stack_a = NULL;
	ft_init_stack(&argv[1], &stack_a);
	if (ft_check_sorted(&stack_a))
	{
		ft_free_stack(&stack_a);
		return (0);
	}
	data.a = &stack_a;
	part_a = NULL;
	if (ft_partnew_front(&part_a, ft_len_stack(stack_a)))
	{
		ft_free_stack(&stack_a);
		exit(1);
	}
	data.part_a = &part_a;
	ft_push_swap(data);
	exit(0);
}
