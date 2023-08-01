/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:49:43 by preina-g          #+#    #+#             */
/*   Updated: 2023/07/26 11:51:13 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_putnbr(const char *str, int i)
{
	int	num;

	num = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	num;

	num = 0;
	nb = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			nb = nb * -1;
			i++;
		}
		else
			i++;
	}
	num = ft_putnbr(str, i);
	return (num * nb);
}
/*timeval is used for determinate a certain interval of time*/

long long	ft_get_timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_print_msg(t_data *data, const char *msg, int philo_id)
{
	pthread_mutex_lock(data->print_msg);
	if (data->dead == FALSE)
	{
		printf("%lli ", (ft_get_timestamp() - data->timestamp));
		printf(" philo %i %s\n", philo_id + 1, msg);
	}
	pthread_mutex_unlock(data->print_msg);
}

void	ft_sleep(long long time, t_data *data)
{
	long long	timed;

	timed = ft_get_timestamp();
	while (data->dead == FALSE)
	{
		if ((ft_get_timestamp() - timed) >= time)
			break ;
		usleep(50);
	}
}
