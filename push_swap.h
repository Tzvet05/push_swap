/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttrave <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:39:22 by ttrave            #+#    #+#             */
/*   Updated: 2024/02/15 16:35:55 by ttrave           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ----- INCLUDES ----- */

# include <stdio.h>// delete this include ------------------------------------------
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

/* ----- MACROS ----- */

# define STDOUT 1 //pas utile avec rework du buffer d'instructions -----------------

// Instructions macros
# define SA		"sa\n"
# define SB		"sb\n"
# define SS		"ss\n"
# define PA		"pa\n"
# define PB		"pb\n"
# define RA		"ra\n"
# define RB		"rb\n"
# define RR		"rr\n"
# define RRA		"rra\n"
# define RRB		"rrb\n"
# define RRR		"rrr\n"

/* ----- STRUCTURE ----- */

// Double circular linked list
typedef struct s_idlst
{
	int				n;
	struct s_idlst	*next;
	struct s_idlst	*prev;
}	t_stack;

// Partitions lengths
typedef struct s_partition
{
	size_t				len;
	struct s_partition	*next;
}	t_partition;

// Centralised data storage
typedef struct s_storage
{
	t_stack		**a;
	t_stack		**b;
	t_partition	**part_a;
	t_partition	**part_b;
	t_list		**instructions;
}	t_storage;

/* ----- PROTOTYPES ----- */

// push_swap.c
int		main(int argc, char **argv);

// ft_stack_initialization1.c
void	ft_init_stack(char **argv, t_stack **stack);

// ft_stack_initialization2.c
void	ft_link_stack(t_stack **stack);

// ft_sort.c
char	ft_presort_a(t_storage *data);

// ft_sort_partitions.c
char	ft_sort_partition_a(t_storage *data);

// ft_get_median.c
t_stack	*ft_median(t_stack **stack, t_partition **part);

// ft_partitioning.c
size_t	ft_len_stack(t_stack *stack);
char	ft_partnew_front(t_partition **part, size_t n);
char	ft_partition(t_partition **part_dst, t_partition **part_src);

// ft_sort_utils.c
size_t	ft_len_partition(t_stack *stack, t_list *pivot);

// ft_utils.c
ssize_t	ft_puterr(void);
void	ft_free_stack(t_stack **stack);
void	ft_free_part(t_partition **part);
void	ft_free_all(t_storage *data);
char	ft_greater(int n1, int n2);
char	ft_lesser(int n1, int n2);

// ft_instructions1.c
char	instr(char *instruction, t_stack **a, t_stack **b);

// ft_instructions2.c
void	rrx(t_stack **stack, char *instruction);
void	rrr(t_stack **stack1, t_stack **stack2, char *instruction);
void	rx(t_stack **stack, char *instruction);
void	rr(t_stack **stack1, t_stack **stack2, char *instruction);

// ft_opti_instr_buff.c
void	ft_opti_instructions(t_list **instructions);

// DO NOT PUSH ---------------------------------------------------------------------
void	pstk(t_stack **lst);//delete these functions
void	plst(t_list **lst);
void	ppart(t_partition **part);

#endif
