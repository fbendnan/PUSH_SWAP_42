/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_instructions_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:26:56 by fbendnan          #+#    #+#             */
/*   Updated: 2026/01/02 10:32:43 by fbendnan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	bonus_rrb(t_stack **b)
{
	t_stack	*prev;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	prev = NULL;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
}

void	bonus_rra(t_stack **a)
{
	t_stack	*prev;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
}

void	bonus_rrr(t_stack **a, t_stack **b)
{
	bonus_rra(a);
	bonus_rrb(b);
}
