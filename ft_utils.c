/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:14:23 by ttrave            #+#    #+#             */
/*   Updated: 2024/02/24 13:33:41 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	ft_puterr(void)
{
	return (write(2, "Error\n", 6));
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*previous;
	t_stack	*current;

	if (!*stack)
		return ;
	current = *stack;
	current->prev->next = NULL;
	while (current)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
}

void	ft_free_part(t_partition **part)
{
	t_partition	*current;
	t_partition	*previous;

	current = *part;
	while (current)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
}

void	ft_free_all(t_storage *data)
{
	ft_free_stack(data->a);
	ft_free_stack(data->b);
	ft_free_part(data->part_a);
	ft_free_part(data->part_b);
	ft_lstclear(data->instructions, &free);
}

char	ft_greater(int n1, int n2)
{
	return (n1 >= n2);
}

char	ft_lesser(int n1, int n2)
{
	return (n1 <= n2);
}
