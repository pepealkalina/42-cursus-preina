/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 12:18:00 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/03/25 16:16:22 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lower_pos(t_stack *s)
{
	int	l_pos;
	int	l_index;

	l_index = 2147483647;
	ft_reset_pos(s);
	l_pos = s->pos;
	while (s)
	{
		if (s->index < l_index)
		{
			l_pos = s->pos;
			l_index = s->index;
		}
		s = s->next;
	}
	return (l_pos);
}

void	ft_shift_stack(t_stack **a)
{
	int	l_pos;
	int	s_len;

	l_pos = ft_lower_pos(*a);
	s_len = ft_stack_size(*a);
	if (l_pos > s_len / 2)
	{
		while (l_pos < s_len)
		{
			reverse_rotate(a);
			write(1, "rra\n", 4);
			l_pos++;
		}
	}
	else
	{
		while (l_pos > 0)
		{
			rotate(a);
			write(1, "ra\n", 3);
			l_pos--;
		}
	}
}
