/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 09:51:49 by fbendnan          #+#    #+#             */
/*   Updated: 2026/01/02 10:31:13 by fbendnan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_three(t_stack **a)
{
	int	num_one ;
	int	num_two;
	int	num_three;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	num_one = (*a)->value;
	num_two = (*a)->next->value;
	num_three = (*a)->next->next->value;
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

void	wich_one(t_stack **a, t_stack **b, int size_a, int *i)
{
	if (size_a == 4)
	{
		if ((*a)->rank < 1)
		{
			pb(a, b);
			(*i)++;
		}
		else if ((*a)->rank >= 1)
			ra(a);
	}
	if (size_a == 5)
	{
		if ((*a)->rank <= 1)
		{
			pb(a, b);
			(*i)++;
		}
		else if ((*a)->rank > 1)
			ra(a);
	}
}

void	sorting_five_and_four(t_stack **a, t_stack **b, int size_a)
{
	int	i;

	if (size_a == 5)
		i = 0;
	else
		i = 1;
	while (i < 2)
	{
		wich_one(a, b, size_a, &i);
		if (i == 2)
			break ;
	}
	sorting_three(a);
	if (size_a == 5)
	{
		if (*b && (*b)->next && (*b)->rank < (*b)->next->rank)
			sb(b);
		if (*b)
			pa(a, b);
	}
	if (*b)
		pa(a, b);
}

void	fill_stack_b(t_stack **a, t_stack **b, int a_size, int chunk_start)
{
	int	chunk_end;

	if (a_size <= 100)
		chunk_end = a_size / 6;
	else
		chunk_end = a_size / 14;
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

void	chunk_sort_100_500(t_stack **a, t_stack **b, int stack_size)
{
	int	max_rank_index;
	int	max_rank;
	int	chunk_start;

	chunk_start = 0;
	fill_stack_b(a, b, stack_size, chunk_start);
	while ((*b))
	{
		stack_size = ft_stack_size(*b);
		search_max_rank_and_i(*b, &max_rank, &max_rank_index);
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
