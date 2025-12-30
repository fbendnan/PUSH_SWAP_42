/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:44:37 by fbendnan          #+#    #+#             */
/*   Updated: 2025/12/30 12:22:05 by fbendnan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (*a)
	{
		free(*a);
		*a = (*a)->next;
	}
}

int	main(int argc, char *argv[])
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
		return (free_stack(&head_a), 1);
	if (is_sorted(head_a))
		return (free_stack(&head_a), 0);
	set_rank_and_cal_stack_size(head_a, &size_a);
	if (size_a == 2)
		sa(&head_a);
	else if (size_a == 3)
		sorting_three(&head_a);
	else if (size_a == 5 || size_a == 4)
		sorting_five_and_four(&head_a, &head_b, size_a);
	else
		chunk_sort_100_500(&head_a, &head_b, size_a);
	t_stack *tmp = head_a;
	while (tmp)
	{
		printf("%d => %d \n", tmp->value, tmp->rank);
		tmp = tmp->next;
	}
	free_stack(&head_a);
	return (0);
}
