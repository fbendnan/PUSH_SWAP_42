# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/27 00:44:33 by fbendnan          #+#    #+#              #
#    Updated: 2026/01/01 15:48:30 by fbendnan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = cc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

SRCS = push_istructions.c push_swap.c split.c helpers_one.c\
  swap_instructions.c check_errors.c helpers_two.c reverse_rotate_instructions.c\
  rotate_instructions.c helpers_three.c sorting_algo.c main.c

SRCSB = helpers_one.c bonus_instructions.c bonus_instructions_two.c check_errors.c\
  bonus_instructions_three.c split.c helpers_two.c helpers_three.c checker.c get_next_line.c \
  get_next_line_utils.c push_swap.c

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address -g3 $(OBJS) -o $(NAME)

bonus : $(OBJSB)
	$(CC) $(CFLAGS) -fsanitize=address -g3 $(OBJSB) -o $(BONUS_NAME)

clean : 
	rm -rf $(OBJS) $(OBJSB)

fclean : clean
	rm -rf $(NAME) $(BONUS_NAME)

re : fclean all 

.PHONY : all clean fclean re bonus