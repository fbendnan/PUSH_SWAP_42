# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/27 00:44:33 by fbendnan          #+#    #+#              #
#    Updated: 2025/12/29 17:30:16 by fbendnan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

SRCS = helpers.c  push_istructions.c  push_swap.c reverse_rotate_instructions.c\
  rotate_instructions.c  swap_instructions.c check_errors.c split.c sorting_algo.c main.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME)

clean : 
	rm -rf $(OBJS) 

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re