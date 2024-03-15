/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:39:22 by ttrave            #+#    #+#             */
/*   Updated: 2024/03/09 15:28:13 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

/* ----- INCLUDES ----- */

# include "./../libft/hdr/libft.h"
# include <unistd.h>
# include <stdlib.h>

/* ----- MACROS ----- */

// Instructions macros
# define SA	"sa\n"
# define SB	"sb\n"
# define SS	"ss\n"
# define PA	"pa\n"
# define PB	"pb\n"
# define RA	"ra\n"
# define RB	"rb\n"
# define RR	"rr\n"
# define RRA	"rra\n"
# define RRB	"rrb\n"
# define RRR	"rrr\n"

/* ----- STRUCTURE ----- */

// Double circular linked list
typedef struct s_idlst
{
	int				n;
	struct s_idlst	*next;
	struct s_idlst	*prev;
}	t_stack;

/* ----- PROTOTYPES ----- */

// push_swap_bonus.c
int		main(int argc, char **argv);

// ft_stack_initialization1_bonus.c
void	ft_init_stack(char **argv, t_stack **stack);

// ft_stack_initialization2_bonus.c
void	ft_link_stack(t_stack **stack);

// ft_instructions1_bonus.c
void	instr(char *instruction, t_stack **a, t_stack **b);

// ft_instructions2_bonus.c
void	rr(t_stack **stack1, t_stack **stack2);
void	rrx(t_stack **stack);
void	rrr(t_stack **stack1, t_stack **stack2);

// ft_utils_bonus.c
ssize_t	ft_puterr(void);
void	ft_free_stack(t_stack **stack);

#endif
