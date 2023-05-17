/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:33:50 by preina-g          #+#    #+#             */
/*   Updated: 2023/03/25 16:16:27 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_4(t_stack **a, t_stack **b)
{
	int	l_pos;

	l_pos = ft_lower_pos(*a);
	while (l_pos)
	{
		rotate(a);
		write(1, "ra\n", 3);
		l_pos--;
	}
	push(a, b);
	write(1, "pb\n", 3);
	ft_sort_three(a, b);
	push(b, a);
	write(1, "pa\n", 3);
}

void	ft_move_three(t_stack **stack)
{
	if ((*stack)->index > (*stack)->next->index
		&& (*stack)->index < (*stack)->next->next->index)
	{
		swap((*stack));
		write(1, "sa\n", 3);
	}
	else if ((*stack)->index < (*stack)->next->index
		&& (*stack)->next->index > (*stack)->next->next->index)
	{
		reverse_rotate(stack);
		write(1, "rra\n", 4);
	}
	else if ((*stack)->index > (*stack)->next->index
		&& (*stack)->index > (*stack)->next->next->index)
	{
		rotate(stack);
		write(1, "ra\n", 3);
	}
	else if ((*stack)->index < (*stack)->next->index
		&& (*stack)->next->index < (*stack)->next->next->index)
		return ;
	ft_move_three(stack);
}

int	ft_sort_three(t_stack **a, t_stack **b)
{
	if (!a || !b)
		return (FALSE);
	if (ft_stack_size(*a) == 4)
	{
		ft_sort_4(a, b);
		return (TRUE);
	}
	ft_move_three(a);
	ft_reset_pos((*a));
	return (TRUE);
}
