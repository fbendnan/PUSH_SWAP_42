/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_instructions_three.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:30:17 by fbendnan          #+#    #+#             */
/*   Updated: 2026/01/01 15:31:08 by fbendnan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	bonus_ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = (*a);
	*a = (first)->next;
	first->next = NULL;
	last = (*a);
	while (last->next)
		last = (last)->next;
	last->next = first;
}

void	bonus_rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (!(b) || !(*b) || !(*b)->next)
		return ;
	first = (*b);
	*b = (first)->next;
	first->next = NULL;
	last = (*b);
	while (last->next)
		last = (last)->next;
	last->next = first;
}

void	bonus_rr(t_stack **a, t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !(*a) || !(*a)->next || !(b) || !(*b) || !(*b)->next)
		return ;
	first = (*a);
	*a = (first)->next;
	first->next = NULL;
	last = (*a);
	while (last->next)
		last = (last)->next;
	last->next = first;
	first = (*b);
	*b = (first)->next;
	first->next = NULL;
	last = (*b);
	while (last->next)
		last = (last)->next;
	last->next = first;
}
