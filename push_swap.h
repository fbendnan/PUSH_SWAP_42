#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
typedef struct s_stack
{
    int value;
    int	index;
	struct s_stack *next;
}   t_stack;

void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst, void (*del)(void*));

#endif
