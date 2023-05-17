/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:06:25 by preina-g          #+#    #+#             */
/*   Updated: 2023/03/23 12:34:43 by preina-g      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;

	temp = (*stack);
	(*stack) = (*stack)->next;
	tail = ft_last_node(*stack);
	temp->next = NULL;
	tail->next = temp;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = ft_last_node(*stack);
	before_tail = ft_before_last_node(*stack);
	temp = (*stack);
	(*stack) = tail;
	(*stack)->next = temp;
	before_tail->next = NULL;
}

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (!stack_a)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = (*stack_b);
	(*stack_b) = (*stack_a);
	(*stack_a) = temp;
}
