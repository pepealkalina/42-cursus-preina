/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:57:31 by preina-g          #+#    #+#             */
/*   Updated: 2023/07/05 09:10:16 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_num(const char *num)
{
	int	i;

	i = -1;
	while (num[++i])
	{
		if (!(num[i] >= '0' && num[i] <= '9'))
			return (FALSE);
	}
	return (TRUE);
}

void	ft_save_data(const char *num, int pos, t_data *data)
{
	if (pos == 1)
	{
		data->n_philo = ft_atoi(num);
		printf("data->n_philo: %d\n", data->n_philo);
	}
	else if (pos == 2)
	{
		data->die_time = ft_atoi(num);
		printf("data->die_time: %d\n", data->die_time);
	}
	else if (pos == 3)
	{
		data->eat_time = ft_atoi(num);
		printf("data->eat_time: %d\n", data->eat_time);
	}
	else if (pos == 4)
	{
		data->sleep_time = ft_atoi(num);
		printf("data->sleep_time: %d\n", data->sleep_time);
	}
	else if (pos == 5)
	{
		data->n_times_each_philosopher_must_eat = ft_atoi(num);
		printf("data->n_times_each_philosopher_must_eat: %d\n", data->n_times_each_philosopher_must_eat);
	}
}

int	ft_arg_parser(const char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_is_num(argv[i]) == FALSE)
			return (FALSE);
		else
			ft_save_data(argv[i], i, data);
	}
	return (TRUE);
}
