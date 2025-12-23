/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:41:19 by fbendnan          #+#    #+#             */
/*   Updated: 2025/12/23 12:58:48 by fbendnan         ###   ########.fr       */
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

void	rr(t_stack **a, t_stack **b)
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
	if (!(b) || !(*b) || !(*b)->next)
		return ;
	first = (*b);
	*b = (first)->next;
	first->next = NULL;
	last = (*b);
	while (last->next)
		last = (last)->next;
	last->next = first;
	write(1, "rr/n", 3);
}
