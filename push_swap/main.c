/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:31:17 by preina-g          #+#    #+#             */
/*   Updated: 2023/03/25 18:49:51 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_free_list(t_stack **lst)
{
	t_stack	*temp;

	if (!lst)
		return ;
	while ((*lst))
	{
		temp = (*lst);
		(*lst) = (*lst)->next;
		free(temp);
	}
	free((*lst));
	(*lst) = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	else if (ft_check_input(argv, argc, &data, 1) == FALSE)
		exit(write(1, "Error\n", 6));
	else if (data.num_list == NULL)
		exit(write(1, "Error\n", 6));
	push_swap_main(&data);
	return (0);
}
