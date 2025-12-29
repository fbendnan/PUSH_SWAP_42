#include "push_swap.h"

void	sorting_three(t_stack **a)
{
	int num_one,   num_two,	num_three;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return;
	num_one = (*a)->value;
	num_two = (*a)->next->value;
	num_three = (*a)->next->next->value;
	if (num_one < num_two && num_two < num_three)
		return ;
	if (num_one < num_two && num_two > num_three && num_one < num_three)
		return (sa(a), ra(a));
	if (num_one > num_two && num_two < num_three && num_one < num_three)
		return (sa(a));
	if (num_one < num_two && num_two > num_three && num_one > num_three)
		return (rra(a));
	if (num_one > num_two && num_two < num_three && num_one > num_three)
		return (ra(a));
	if (num_one > num_two && num_two > num_three && num_one > num_three)
		return (ra(a), sa(a));
}

// void	sorting_five_and_four(t_stack **a, t_stack **b)
// {

// }

void search_max_rank_and_her_index(t_stack *b, int *max_rank, int *max_rank_index)
{
	int	tmp, i;

	*max_rank_index = 0;
	tmp = b->rank;
	i = 0;
	while (b)
	{
		if (b->rank >= tmp)
		{
			*max_rank = b->rank;
			*max_rank_index = i;
			tmp = b->rank;
		}
		b = b->next;
		i++;
	}
}

void	fill_stack_b_with_stack_a(t_stack **a, t_stack **b, int stack_a_size)
{
	int chunk_start,	chunk_end;

	chunk_start = 0;
	if (stack_a_size <= 100)
		chunk_end = stack_a_size / 6;
	else
		chunk_end = stack_a_size / 14;
	while (*a)
	{
		if ((*a)->rank <= chunk_start)
		{
			pb(a, b);
			rb(b);
			chunk_start++;
			chunk_end++;
		}
		else if ((*a)->rank <= chunk_end)
		{
			pb(a, b);
			chunk_start++;
			chunk_end++;
		}
		else
			ra(a);
	}
}

void chunk_sort_100_500(t_stack **a, t_stack **b, int stack_size)
{
	int	max_rank_index,	max_rank;

	fill_stack_b_with_stack_a(a, b, stack_size);
	while ((*b))
	{
		stack_size = ft_stack_size(*b);
		search_max_rank_and_her_index(*b, &max_rank, &max_rank_index);
		if (max_rank_index <= stack_size / 2)
		{
			while ((*b)->rank != max_rank)
				rb(b);
		}
		else
		{
			while ((*b)->rank != max_rank)
				rrb(b);
		}
		pa(a, b);
	}
}