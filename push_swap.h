/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:41:30 by fbendnan          #+#    #+#             */
/*   Updated: 2025/12/31 15:03:27 by fbendnan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
}	t_stack;

void	search_max_rank_and_i(t_stack *b, int *max_rank, int *max_rank_index);
void	set_rank_and_cal_stack_size(t_stack *a, int *size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int	empty_srting_inside_argv(char **argv);
int	is_input_just_spaces(char **argv);
char	**ft_split(char const *s, char c);
void	free_split(char **args);
size_t	ft_strlen(const char *str);
int		is_sorted(t_stack *a);
void	free_stack(t_stack **a);
long	ft_atol(const char *nptr);
int		ft_stack_size(t_stack *b);
int		ft_isdigit(int c);
int		fill_stack_a(char *argv[], t_stack **head_a);
int		check_error(char **args, int j, long *tmp, t_stack **head_a);
void	chunk_sort_100_500(t_stack **a, t_stack **b, int stack_size);
void	sorting_five_and_four(t_stack **a, t_stack **b, int size_a);
void	sorting_three(t_stack **a);
void	rrr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);

#endif
