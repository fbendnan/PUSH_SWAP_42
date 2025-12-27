/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:44:37 by fbendnan          #+#    #+#             */
/*   Updated: 2025/12/27 00:44:38 by fbendnan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack	*head_a;
	t_stack	*head_b;

	head_a = NULL;
	head_b = NULL;

	if (argc < 2)
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		return (1);
	if (!fill_stack_a(argv, &head_a))
		return (1);
	
	return (0);
}
