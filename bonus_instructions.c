/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:25:31 by fbendnan          #+#    #+#             */
/*   Updated: 2026/01/01 15:31:39 by fbendnan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	bonus_sa(t_stack **a)
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
}

void	bonus_sb(t_stack **b)
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
}

void	bonus_ss(t_stack **a, t_stack **b)
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
}

void	bonus_pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	bonus_pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}
