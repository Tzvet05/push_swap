/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 22:14:23 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/09 15:26:39 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

ssize_t	ft_puterr(void)
{
	return (write(2, "Error\n", 6));
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*end;
	t_stack	*previous;
	t_stack	*current;

	if (!*stack)
		return ;
	current = *stack;
	end = current->prev;
	while (current != end)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
	free(current);
}
