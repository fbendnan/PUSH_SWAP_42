#include "push_swap.h"

void pa(t_stack **a, t_stack **b)
{
	ft_lstadd_front(a, *b);
	write(1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
	ft_lstadd_front(b, *a);
	write(1, "pb\n", 3);
}