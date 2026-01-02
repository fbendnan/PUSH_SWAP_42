/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:45:50 by fbendnan          #+#    #+#             */
/*   Updated: 2026/01/01 15:36:48 by fbendnan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_streq(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] == '\0' && s2[i] == '\0');
}

int	check_instruction(char *str, t_stack **a, t_stack **b)
{
	if (ft_streq("sa\n", str))
		return (bonus_sa(a), 1);
	else if (ft_streq("sb\n", str))
		return (bonus_sb(b), 1);
	else if (ft_streq("ss\n", str))
		return (bonus_ss(a, b), 1);
	else if (ft_streq("pa\n", str))
		return (bonus_pa(a, b), 1);
	else if (ft_streq("pb\n", str))
		return (bonus_pb(a, b), 1);
	else if (ft_streq("ra\n", str))
		return (bonus_ra(a), 1);
	else if (ft_streq("rb\n", str))
		return (bonus_rb(b), 1);
	else if (ft_streq("rr\n", str))
		return (bonus_rr(a, b), 1);
	else if (ft_streq("rra\n", str))
		return (bonus_rra(a), 1);
	else if (ft_streq("rrb\n", str))
		return (bonus_rrb(b), 1);
	else if (ft_streq("rrr\n", str))
		return (bonus_rrr(a, b), 1);
	else
		return (0);
}

void	execute_instructions(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break;
		if (!check_instruction(line, a, b))
		{
			free(line);
			free_stack(a);
			free_stack(b);
			write(2, "Error\n", 6);
			return;
		}
		free(line);
	}
	if (is_sorted(*a) && *b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(a);
	free_stack(b);
}

int main(int argc, char *argv[])
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc < 2)
		return (0);
	if (is_input_just_spaces(argv) || empty_srting_inside_argv(argv))
		return ((write(2, "Error\n", 6)), 1);
	if (!fill_stack_a(argv, &head_a))
		return (free_stack(&head_a), 1);
	execute_instructions(&head_a, &head_b);
}
