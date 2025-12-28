/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:44:37 by fbendnan          #+#    #+#             */
/*   Updated: 2025/12/28 19:12:13 by fbendnan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rank_and_cal_stack_size(t_stack *a, int *size)
{
	t_stack	*tmp_stack;
	t_stack	*tmp_stack_d;
	int		rank;

	*size = 1;
	tmp_stack = a;
	while (tmp_stack)
	{
		tmp_stack_d = a;
		rank = 1;
		while (tmp_stack_d)
		{
			if (tmp_stack_d->value < tmp_stack->value)
				rank++;
			(tmp_stack_d) = (tmp_stack_d)->next;
		}
		size++;
		(tmp_stack)->rank = rank;
		(tmp_stack) = (tmp_stack)->next;
	}
}

int is_sorted(t_stack *a)
{
	while (a)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		size_a;

	head_a = NULL;
	head_b = NULL;

	if (argc < 2)
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		return (1);
	if (!fill_stack_a(argv, &head_a))
		return (1);
	if(is_sorted(head_a))
		return (0);
	set_rank_and_cal_stack_size(head_a, &size_a);
	if (size_a == 3)
		sorting_three(&head_a);
	else if(size_a == 5 || size_a == 4)
		sorting_five_and_four(&head_a, &head_b);
	else
		chunk_sort_100_500(&head_a, &head_b);
	return (0);
}
