/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:41:25 by fbendnan          #+#    #+#             */
/*   Updated: 2025/12/31 16:18:51 by fbendnan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	int	tmp_value;
	int	tmp_rank;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp_value = (*a)->value;
	tmp_rank = (*a)->rank;
	(*a)->value = (*a)->next->value;
	(*a)->rank = (*a)->next->rank;
	(*a)->next->value = tmp_value;
	(*a)->next->rank = tmp_rank;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	int	tmp_value;
	int	tmp_rank;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp_value = (*b)->value;
	tmp_rank = (*b)->rank;
	(*b)->value = (*b)->next->value;
	(*b)->rank = (*b)->next->rank;
	(*b)->next->value = tmp_value;
	(*b)->next->rank = tmp_rank;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	int	tmp_value;
	int	tmp_rank;

	if (!a || !*a || !(*a)->next || !b || !*b || !(*b)->next)
		return ;
	tmp_value = (*a)->value;
	tmp_rank = (*a)->rank;
	(*a)->value = (*a)->next->value;
	(*a)->rank = (*a)->next->rank;
	(*a)->next->value = tmp_value;
	(*a)->next->rank = tmp_rank;
	tmp_value = (*b)->value;
	tmp_rank = (*b)->rank;
	(*b)->value = (*b)->next->value;
	(*b)->rank = (*b)->next->rank;
	(*b)->next->value = tmp_value;
	(*b)->next->rank = tmp_rank;
	write(1, "ss\n", 3);
}
