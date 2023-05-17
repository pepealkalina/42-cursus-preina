/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:37:03 by preina-g          #+#    #+#             */
/*   Updated: 2023/03/25 19:37:05 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_input(char **argv, int argc, t_data *data, int flag)
{
	if (argc == 2 && flag == 1)
	{
		ft_split_argv(argv[1], data);
		if (ft_check_input(data->split_argu,
				data->split_len + 1, data, 0) == FALSE)
			return (FALSE);
	}
	else
	{
		data->lst_len = argc - 1;
		if (ft_is_num(argv) == FALSE)
		{
			return (FALSE);
		}
		else if (ft_check_dup(argv, argc, data) == FALSE)
		{
			return (FALSE);
		}
	}
	return (TRUE);
}
