/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:01:09 by fbendnan          #+#    #+#             */
/*   Updated: 2026/01/02 10:32:26 by fbendnan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
