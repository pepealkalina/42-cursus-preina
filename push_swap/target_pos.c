/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:20:23 by preina-g       #+#    #+#             */
/*   Updated: 2023/03/24 13:28:30 by preina-g      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_target_pos(t_stack *a, int index, int tar_pos, long tar_index)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->index > index && tmp->index < tar_index)
		{
			tar_index = tmp->index;
			tar_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (tar_index != 2147483647)
		return (tar_pos);
	tmp = a;
	while (tmp)
	{
		if (tmp->index < tar_index)
		{
			tar_index = tmp->index;
			tar_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (tar_pos);
}

void	ft_target_pos(t_stack *a, t_stack *b)
{
	int		tar_pos;
	t_stack	*tmp;

	tmp = b;
	ft_reset_pos(a);
	ft_reset_pos(b);
	tar_pos = 0;
	while (tmp)
	{
		tar_pos = ft_get_target_pos(a, tmp->index, tar_pos, 2147483647);
		tmp->target_pos = tar_pos;
		tmp = tmp->next;
	}
}
