/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:54:22 by preina-g          #+#    #+#             */
/*   Updated: 2023/03/25 16:16:32 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_half(t_stack **a, t_stack **b, int len, int const_size)
{
	if (len == 0)
		return ;
	if ((*a)->index <= const_size / 2)
	{
		push(a, b);
		write(1, "pb\n", 3);
		len--;
	}
	else
	{
		rotate(a);
		write(1, "ra\n", 3);
		len--;
	}
	ft_first_half(a, b, len, const_size);
}

void	ft_second_half(t_stack **a, t_stack **b, int len)
{
	if (len <= 3)
		return ;
	push(a, b);
	write(1, "pb\n", 3);
	len--;
	ft_second_half(a, b, len);
}

int	ft_ordered(t_stack *a)
{
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	ft_left_three(t_stack **a, t_stack **b)
{
	int	len;
	int	const_size;

	len = ft_stack_size((*a));
	const_size = len;
	ft_first_half(a, b, const_size, len);
	if (len % 2)
		len++;
	ft_second_half(a, b, len / 2);
}

void	ft_sort(t_stack **a, t_stack **b)
{
	ft_left_three(a, b);
	ft_sort_three(a, b);
	while ((*b))
	{
		ft_target_pos(*a, *b);
		ft_cost(a, b);
		ft_move(a, b);
	}
	if (!ft_ordered(*a))
		ft_shift_stack(a);
}
