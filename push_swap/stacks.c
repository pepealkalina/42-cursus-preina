/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:27:14 by preina-g          #+#    #+#             */
/*   Updated: 2023/03/25 19:38:12 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(t_stack *stack)
{
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->next = NULL;
	return (stack);
}

void	add_int(t_stack *stack, int value, int pos)
{
	t_stack	*current;

	current = stack;
	while (current->next)
		current = current->next;
	current->next = new_node(current->next);
	current->next->value = value;
	current->next->pos = pos;
}

t_stack	*ft_fill_stack(t_data *data, t_stack *stack)
{
	int	i;
	int	j;
	int	len;

	stack = new_node(stack);
	if (stack == NULL)
		return (NULL);
	len = data->lst_len;
	stack->value = data->num_list[0];
	i = 1;
	j = 1;
	while (i < len)
	{
		add_int(stack, data->num_list[i], j);
		j++;
		i++;
	}
	return (stack);
}
