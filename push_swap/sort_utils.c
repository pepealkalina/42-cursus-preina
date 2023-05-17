/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:52:54 by preina-g          #+#    #+#             */
/*   Updated: 2023/03/25 16:16:29 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		ft_rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	ft_rr_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		ft_rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	ft_rb(t_stack **b, int cost_b)
{
	while (cost_b)
	{
		if (cost_b > 0)
		{
			rotate(b);
			write(1, "rb\n", 3);
			cost_b--;
		}
		else if (cost_b < 0)
		{
			reverse_rotate(b);
			write(1, "rrb\n", 4);
			cost_b++;
		}
	}
}

void	ft_ra(t_stack **a, int cost_a)
{
	while (cost_a)
	{
		if (cost_a > 0)
		{
			cost_a--;
			rotate(a);
			write(1, "ra\n", 3);
		}
		else if (cost_a < 0)
		{
			cost_a++;
			reverse_rotate(a);
			write(1, "rra\n", 4);
		}
	}
}
