/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:13:30 by preina-g          #+#    #+#             */
/*   Updated: 2023/03/25 16:22:51 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_set_index_init(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack != NULL)
	{
		stack->index = -1;
		len++;
		stack = stack->next;
	}
	return (len);
}

int	ft_set_min(t_stack *stack)
{
	long	min;

	min = 2147483647;
	while (stack != NULL)
	{
		if (min > stack->value && stack->index == -1)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	ft_set_max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack != NULL)
	{
		if (max < stack->value && stack->index == -1)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

void	ft_set_min_index(t_stack *stack, int min, int index)
{
	while (stack != NULL)
	{
		if (stack->value == min && stack->index == -1)
			stack->index = index;
		stack = stack->next;
	}
}

void	ft_set_index(t_stack *stack)
{
	int	index;
	int	len;

	if (ft_ordered(stack) == TRUE)
		exit(EXIT_SUCCESS);
	index = 1;
	len = ft_set_index_init(stack);
	while (index <= len)
	{
		ft_set_min_index(stack, ft_set_min(stack), index);
		index++;
	}
	ft_set_min_index(stack, ft_set_max(stack), len);
}
