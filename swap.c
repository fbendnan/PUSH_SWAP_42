#include "push_swap.h"

typedef struct s_stack
{
    int value;
    int	index;
	struct s_stack *next;
}   t_stack;

void sa(t_stack **a)
{
	int	tmp;

	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	write(1, "sa\n", 3);
}