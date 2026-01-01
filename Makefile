# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/27 00:44:33 by fbendnan          #+#    #+#              #
#    Updated: 2025/12/31 17:48:20 by fbendnan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = cc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

SRCS = helpers_one.c  push_istructions.c  push_swap.c reverse_rotate_instructions.c\
  rotate_instructions.c  swap_instructions.c check_errors.c split.c sorting_algo.c\
  main.c helpers_two.c

SRCSB = checker.c get_next_line_utils.c push_istructions.c push_swap.c split.c helpers_one.c\
  swap_instructions.c check_errors.c helpers_two.c get_next_line.c reverse_rotate_instructions.c\
  rotate_instructions.c

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address -g3 $(OBJS) -o $(NAME)

bonus : $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address -g3 $(OBJSB) -o $(BONUS_NAME)

clean : 
	rm -rf $(OBJS) 

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus