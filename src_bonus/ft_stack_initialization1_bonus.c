/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_initialization1_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 00:48:17 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/09 15:26:15 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	ft_get_nbr(char *arg, size_t *i, int *nbr)
{
	char	sign;
	size_t	tmp;

	sign = 0;
	while (arg[*i] == '-' || arg[*i] == '+')
	{
		sign = sign ^ (arg[*i] == '-');
		(*i)++;
	}
	if (!ft_isdigit(arg[*i]))
		return (1);
	tmp = 0;
	while (ft_isdigit(arg[*i]))
	{
		tmp = 10 * tmp + arg[*i] - 48;
		if (tmp > 2147483648 || (!sign && tmp > 2147483647))
			return (1);
		(*i)++;
	}
	if (arg[*i] && arg[*i] != ' ')
		return (1);
	*nbr = (int)tmp;
	if (sign)
		*nbr *= -1;
	return (0);
}

static char	ft_check_duplicate(int nbr, t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	while (node)
	{
		if (nbr == node->n)
			return (1);
		node = node->next;
	}
	return (0);
}

static char	ft_expand_stack(int nbr, t_stack **stack)
{
	t_stack	*node;
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (1);
	new->n = nbr;
	new->next = NULL;
	if (!*stack)
	{
		new->prev = NULL;
		*stack = new;
		return (0);
	}
	node = *stack;
	while (node->next)
		node = node->next;
	new->prev = node;
	node->next = new;
	return (0);
}

static char	ft_parse_arg(char *arg, size_t *i, t_stack **stack)
{
	int	nbr;

	nbr = 0;
	if (ft_in(arg[*i], "+-0123456789"))
	{
		if (ft_get_nbr(arg, i, &nbr))
			return (1);
		if (ft_check_duplicate(nbr, stack))
			return (1);
		if (ft_expand_stack(nbr, stack))
			return (1);
	}
	else if (arg[*i] != ' ')
		return (1);
	else
		(*i)++;
	return (0);
}

void	ft_init_stack(char **argv, t_stack **stack)
{
	size_t	i_arg;
	size_t	i_nbr;

	i_arg = 0;
	while (argv[i_arg])
	{
		i_nbr = 0;
		while (argv[i_arg][i_nbr])
		{
			if (ft_parse_arg(argv[i_arg], &i_nbr, stack))
			{
				ft_free_stack(stack);
				ft_puterr();
				exit(1);
			}
		}
		i_arg++;
	}
	ft_link_stack(stack);
}
