/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbendnan <fbendnan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 17:45:39 by fbendnan          #+#    #+#             */
/*   Updated: 2026/01/01 15:34:15 by fbendnan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "get_next_line.h"

void	bonus_pb(t_stack **a, t_stack **b);
void	bonus_pa(t_stack **a, t_stack **b);
void	bonus_ss(t_stack **a, t_stack **b);
void	bonus_sb(t_stack **b);
void	bonus_sa(t_stack **a);
void	bonus_rrr(t_stack **a, t_stack **b);
void	bonus_rra(t_stack **a);
void	bonus_rrb(t_stack **b);
void	bonus_rr(t_stack **a, t_stack **b);
void	bonus_rb(t_stack **b);
void	bonus_ra(t_stack **a);

#endif