# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/27 00:44:33 by fbendnan          #+#    #+#              #
#    Updated: 2025/12/29 16:20:00 by fbendnan         ###   ########.fr        #
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

# $(NAME) : $(OBJS)
# 	$(AR) $(NAME) $(OBJS)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME)

# %.o : %.c
# 	$(cc) $(CFLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJS) 

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re