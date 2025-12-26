NAME = libft.a

CC = cc

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror

SRCS = helpers.c  push_istructions.c  push_swap.c reverse_rotate_instructions.c\
  rotate_instructions.c  swap_instructions.c check_errors.c split.c




OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c 
	$(CC) -c $(CFLAGS) $< -o $@ 

clean : 
	rm -rf $(OBJS) 

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re