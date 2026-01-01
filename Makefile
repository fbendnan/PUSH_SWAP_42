# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/27 00:44:33 by fbendnan          #+#    #+#              #
#    Updated: 2026/01/01 15:01:28 by fbendnan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = cc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

SRCS = helpers_one.c  push_istructions.c  push_swap.c reverse_rotate_instructions.c\
  rotate_instructions.c  swap_instructions.c check_errors.c split.c sorting_algo.c\
  main.c helpers_two.c helpers_three.c

SRCSB = push_istructions.c push_swap.c checker.c get_next_line_utils.c split.c helpers_one.c\
  swap_instructions.c check_errors.c helpers_two.c get_next_line.c reverse_rotate_instructions.c\
  rotate_instructions.c helpers_three.c

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address -g3 $(OBJS) -o $(NAME)

bonus : $(OBJSB)
	$(CC) $(CFLAGS) -fsanitize=address -g3 $(OBJSB) -o $(BONUS_NAME)

clean : 
	rm -rf $(OBJS) 

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus