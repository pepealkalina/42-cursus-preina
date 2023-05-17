/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:37:05 by preina-g          #+#    #+#             */
/*   Updated: 2023/03/25 19:36:56 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_is_num(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		if (argv[i][0] == '.' || argv[i][0] == '/')
			i++;
		j = -1;
		while (argv[i][++j])
		{
			while (argv[i][j] == ' ')
				j++;
			if (ft_isdigit(argv[i][j]) == 0
				&& (argv[i][j] == '-' || argv[i][j] == '+'))
				j++;
			if (ft_isdigit(argv[i][j]) == 0)
				return (FALSE);
		}
	}
	return (TRUE);
}

int	ft_is_int(char *num)
{
	long long	max;
	long long	min;
	long long	nb;

	max = 2147483648;
	min = -2147483649;
	nb = ft_atoll(num);
	if (nb >= max || nb <= min)
		return (FALSE);
	return (TRUE);
}

int	*ft_atoi_input(char **argv, int argc)
{
	int	*array;
	int	i;
	int	j;

	array = (int *)malloc((argc - 1) * sizeof(int));
	if (!array)
		exit(write(1, "Error\n", 6));
	i = 0;
	j = 0;
	while (argv[j])
	{
		if (argv[j][0] == '.' || argv[j][0] == '/')
			j++;
		if (ft_is_int(argv[j]) == FALSE)
		{
			free(array);
			exit(write(1, "Error\n", 6));
		}
		else
			array[i] = ft_atoll(argv[j]);
		i++;
		j++;
	}
	i = 0;
	return (array);
}

int	ft_check_dup(char **argv, int argc, t_data *data)
{
	int	i;
	int	j;

	data->num_list = ft_atoi_input(argv, argc);
	i = 0;
	while (data->num_list[i])
	{
		j = 0;
		while (data->num_list[j])
		{
			if (data->num_list[j] == data->num_list[i] && j != i)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

void	ft_split_argv(char *argv, t_data *data)
{
	data->split_argu = ft_split(argv, ' ');
	if (data->split_argu == NULL)
		exit(write(1, "Error\n", 6));
	data->split_len = 0;
	while (data->split_argu[data->split_len])
		data->split_len++;
}
