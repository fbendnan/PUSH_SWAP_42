/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:44:48 by fbendnan          #+#    #+#             */
/*   Updated: 2025/12/28 16:24:09 by fbendnan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	err_msg()
{
	write(2, "Error\n", 7);
}

static int error_repetition(t_stack *a, int num)
{
	while (a)
	{
		if (a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}

static int invalid_nb_error(const char *nptr)
{
	int		i;

	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	if (!nptr[i])
		return (1);
	while (nptr[i] && ft_isdigit(nptr[i]))
		i++;
	if (nptr[i])
		return (1);
	return (0);
}

int check_error(char **args, int j, long *tmp, t_stack **head_a)
{
	if(invalid_nb_error(args[j]))
		return (free_split(args), err_msg(), (1));
	*tmp = ft_atoi(args[j]);
	if (*tmp > INT_MAX || *tmp < INT_MIN)
		return (free_split(args), err_msg(), (1));
	if (error_repetition(*head_a, (int)(*tmp)))
		return (free_split(args), err_msg(), (1));
	return (0);
}
