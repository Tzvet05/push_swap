# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttrave <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 18:16:33 by ttrave            #+#    #+#              #
#    Updated: 2023/11/29 18:16:37 by ttrave           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAG = -Wall -Wextra -g#-Werror

SRC =	ft_stack_initialization1.c \
	ft_stack_initialization2.c \
	push_swap.c \
	ft_utils.c \
	ft_instructions1.c \
	ft_instructions2.c \
	ft_opti_instr_buff.c \
	ft_sort.c \
	ft_get_median.c \
	ft_partitioning.c \
	ft_sort_partitions.c \
	DO_NOT_PUSH.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : libft.a $(OBJ)
	$(CC) $(CFLAG) $(OBJ) libft.a -o $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $^ -o $@

libft.a :
	make -C libft/
	mv libft/libft.a ./

fclean : clean
	make fclean -C libft/
	rm -f $(NAME)

clean :
	make clean -C libft/
	rm -f $(OBJ) $(OBJ_BONUS)
	rm -f libft.a

re :	fclean all

.PHONY : all fclean clean re
