/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:41:19 by fbendnan          #+#    #+#             */
/*   Updated: 2025/12/22 01:46:43 by fbendnan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
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
	write(1, "ra/n", 3);
}

void	rb(t_stack **b)
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
	write(1, "rb/n", 3);
}

void	rra(t_stack **a)
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
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
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
	write(1, "rra\n", 4);
}
