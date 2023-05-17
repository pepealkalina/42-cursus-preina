/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:39:41 by preina-g          #+#    #+#             */
/*   Updated: 2023/03/25 16:16:25 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cost(t_stack **a, t_stack **b)
{
	int		size_a;
	int		size_b;
	t_stack	*tmp;
	t_stack	*tmp_a;

	tmp = *b;
	tmp_a = *a;
	size_a = ft_stack_size(tmp_a);
	size_b = ft_stack_size(tmp);
	while (tmp)
	{	
		tmp->cost_b = tmp->pos;
		if (tmp->pos > size_b / 2)
			tmp->cost_b = (size_b - tmp->pos) * -1;
		tmp->cost_a = tmp->target_pos;
		if (tmp->target_pos > size_a / 2)
			tmp->cost_a = (size_a - tmp->target_pos) * -1;
		tmp = tmp->next;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	ft_push_and_rotate(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		ft_rr_both(a, b, &cost_a, &cost_b);
	else if (cost_a < 0 && cost_b < 0)
		ft_rrr_both(a, b, &cost_a, &cost_b);
	ft_ra(a, cost_a);
	ft_rb(b, cost_b);
	pa(a, b);
}

void	ft_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cost_a;
	int		cost_b;
	long	cheapest;

	tmp = *b;
	cheapest = 2147483647;
	while (tmp)
	{
		if (ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b) < ft_abs(cheapest))
		{
			cheapest = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	ft_push_and_rotate(a, b, cost_a, cost_b);
}
