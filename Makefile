# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alassiqu <alassiqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 15:45:06 by alassiqu          #+#    #+#              #
#    Updated: 2024/02/28 21:04:41 by alassiqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
BONUS	= checker
HEADER	= push_swap.h

CC		= cc
CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address -g3
RM		= rm -f

LIB		= 42_libft/libft.a

SRCS	= operations/reverse_rotate_action.c operations/rotate_action.c operations/push_action.c operations/swap_action.c
SRCS	+= stack_utils.c stack_utils_5.c node_utils.c algo.c
SRCS	+= parsing.c error_utils.c algo_utils.c push_swap.c

SRCS_B	= operations/reverse_rotate_action.c operations/rotate_action.c operations/push_action.c operations/swap_action.c
SRCS_B	+= stack_utils.c stack_utils_5.c node_utils.c algo.c
SRCS_B	+= parsing.c error_utils.c algo_utils.c
SRCS_B	+= bonus/get_next_line.c bonus/get_next_line_utils.c bonus/checker.c

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

all: $(NAME)

$(LIB):
	@make -C 42_libft/ --quiet

$(NAME): $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -I $(HEADER) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJS_B) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS_B) $(LIB) -I $(HEADER) -o $(BONUS)

clean:
	@make -C 42_libft/ clean --quiet
	@$(RM) $(OBJS)

clean_bonus:
	@$(RM) $(OBJS_B)

fclean: clean
	@make -C 42_libft/ fclean --quiet
	@$(RM) $(NAME)

fclean_bonus: clean_bonus
	@$(RM) $(BONUS)

re: fclean all

re_bonus: fclean_bonus bonus

.PHONY: all bonus clean clean_bonus fclean fclean_bonus re re_bonus
.SECONDARY: $(OBJS) $(OBJS_B)