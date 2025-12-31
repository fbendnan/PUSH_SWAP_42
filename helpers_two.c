/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 15:03:53 by fbendnan          #+#    #+#             */
/*   Updated: 2025/12/31 16:22:27 by fbendnan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_max_rank_and_i(t_stack *b, int *max_rank, int *max_rank_index)
{
	int	tmp;
	int	i;

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

void	set_rank_and_cal_stack_size(t_stack *a, int *size)
{
	t_stack	*tmp_current;
	t_stack	*tmp_comp;
	int		rank;

	*size = 0;
	tmp_current = a;
	while (tmp_current)
	{
		tmp_comp = a;
		rank = 0;
		while (tmp_comp)
		{
			if (tmp_comp->value < tmp_current->value)
				rank++;
			(tmp_comp) = (tmp_comp)->next;
		}
		(*size)++;
		(tmp_current)->rank = rank;
		(tmp_current) = (tmp_current)->next;
	}
}

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	free_stack(t_stack **a)
{
	t_stack	*cur;
	t_stack	*next;

	if (!a)
		return ;
	cur = *a;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*a = NULL;
}
