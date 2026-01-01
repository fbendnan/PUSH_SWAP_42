/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:45:50 by fbendnan          #+#    #+#             */
/*   Updated: 2025/12/31 17:55:36 by fbendnan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_instructions(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp("sa\n", str))
		return (sa(a), 1);
	else if (ft_strcmp("sb\n", str))
		return (sb(b), 1);
	else if (ft_strcmp("ss\n", str))
		return (ss(a, b), 1);
	else if (ft_strcmp("pa\n", str))
		return (pa(a, b), 1);
	else if (ft_strcmp("pb\n", str))
		return (pb(a, b), 1);
	else if (ft_strcmp("ra\n", str))
		return (ra(a), 1);
	else if (ft_strcmp("rb\n", str))
		return (rb(b), 1);
	else if (ft_strcmp("rr\n", str))
		return (rr(a, b), 1);
	else if (ft_strcmp("rra\n", str))
		return (rra(a), 1);
	else if (ft_strcmp("rrb\n", str))
		return (rrb(b), 1);
	else if (ft_strcmp("rrr\n", str))
		return (rrr(a, b), 1);
	else
		return (0);
}

int main(int argc, char *argv[])
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		size_a;
	char	*line;

	head_a = NULL;
	head_b = NULL;
	if (argc < 2)
		return (0);
	if (is_input_just_spaces(argv) || empty_srting_inside_argv(argv))
		return ((write(2, "Error\n", 6)), 1);
	if (!fill_stack_a(argv, &head_a))
		return (free_stack(&head_a), 1);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			return (1);
		check_instructions(line, &head_a, &head_b);
	}
	if (is_sorted(head_a))
		return (free_stack(&head_a), write(1, "OK\n", 3));
	else
		return(free_stack(&head_a), write(1, "KO\n", 3));
}
