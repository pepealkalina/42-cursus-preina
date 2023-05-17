/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:03:01 by preina-g          #+#    #+#             */
/*   Updated: 2023/03/25 18:38:50 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_2(t_stack *s)
{
	if (s->value > s->next->value)
	{
		swap(s);
		write(1, "sa\n", 3);
	}
}

int	push_swap_main(t_data *data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_fill_stack(data, stack_a);
	ft_set_index(stack_a);
	if (ft_stack_size(stack_a) == 1)
		return (0);
	if (ft_stack_size(stack_a) == 2)
	{
		ft_sort_2(stack_a);
		ft_free_list(&stack_a);
		return (0);
	}
	else if (ft_stack_size(stack_a) == 3 || ft_stack_size(stack_a) == 4)
	{
		ft_sort_three(&stack_a, &stack_b);
		ft_free_list(&stack_a);
		return (0);
	}
	ft_sort(&stack_a, &stack_b);
	ft_free_list(&stack_a);
	return (0);
}
