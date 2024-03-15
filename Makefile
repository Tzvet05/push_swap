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

# Make parameters

NAME = push_swap

NAME_BONUS = checker

COMPILER = cc

CFLAG = -Wall -Wextra -g#-Werror

LIB = libft.a

# Directories

LIB_DIR =	libft/
HDR_DIR =	hdr/
SRC_DIR =	src/
OBJ_DIR =	obj/
SRC_BONUS_DIR =	src_bonus/
OBJ_BONUS_DIR =	obj_bonus/

# Source code (mandatory)

SRC =	ft_stack_initialization1.c \
	ft_stack_initialization2.c \
	push_swap.c \
	ft_utils.c \
	ft_instructions1.c \
	ft_instructions2.c \
	ft_opti_instr_buff.c \
	ft_presort.c \
	ft_sort.c \
	ft_get_median.c \
	ft_get_next_median.c \
	ft_partitioning.c \
	ft_sort_partitions.c \
	DO_NOT_PUSH.c

# Source code (bonus)

SRC_BONUS =	ft_stack_initialization1_bonus.c \
		ft_stack_initialization2_bonus.c \
		push_swap_bonus.c \
		ft_utils_bonus.c \
		ft_instructions1_bonus.c \
		ft_instructions2_bonus.c

# Compiled objects (mandatory)

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# Compiled objects (bonus)

OBJ_BONUS = $(addprefix $(OBJ_BONUS_DIR), $(SRC_BONUS:.c=.o))

# Compilation (mandatory)

$(NAME) : $(LIB) $(OBJ)
	@ echo "$(NAME) compiled (mandatory)."
	@ $(COMPILER) $(CFLAG) $(OBJ) $(LIB) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
	@ $(COMPILER) $(CFLAG) -I $(HDR_DIR) -c $^ -o $@

# Compilation (bonus)

$(NAME_BONUS) : $(LIB) $(OBJ_BONUS)
	@ echo "$(NAME_BONUS) compiled (bonus)."
	@ $(COMPILER) $(CFLAG) $(OBJ_BONUS) $(LIB) -o $(NAME_BONUS)

$(OBJ_BONUS_DIR)%.o : $(SRC_BONUS_DIR)%.c | $(OBJ_BONUS_DIR)
	@ $(COMPILER) $(CFLAG) -I $(HDR_DIR) -c $^ -o $@

# Objects directories

$(OBJ_DIR) $(OBJ_BONUS_DIR) :
	@ mkdir -p $@

# Library

$(LIB) :
	@ make -s -C $(LIB_DIR)
	@ mv $(LIB_DIR)$(LIB) .

# Rules

all : $(NAME)

bonus : $(NAME_BONUS)

fclean : clean
	@ make fclean -s -C $(LIB_DIR)
	@ rm -f $(NAME) $(NAME_BONUS)

clean :
	@ make clean -s -C $(LIB_DIR)
	@ rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@ rm -f $(LIB)

re : fclean all

heheheha :
	@ make -s -C $(LIB_DIR) heheheha

.PHONY : all fclean clean re bonus heheheha
