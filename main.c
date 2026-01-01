/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:44:37 by fbendnan          #+#    #+#             */
/*   Updated: 2025/12/31 16:22:19 by fbendnan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	empty_srting_inside_argv(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	is_input_just_spaces(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '\0')
			return (1);
		i++;
	}
	return (0);
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
	if (is_input_just_spaces(argv) || empty_srting_inside_argv(argv))
		return ((write(2, "Error\n", 6)), 1);
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
	free_stack(&head_a);
	return (0);
}
