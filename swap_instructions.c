#include "push_swap.h"

void sa(t_stack **a)
{
	int	tmp;

	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	write(1, "sa\n", 3);
}

void sb(t_stack **b)
{
	int	tmp;

	tmp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp;
	write(1, "sb\n", 3);
}