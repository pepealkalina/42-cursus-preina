/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:47:57 by preina-g          #+#    #+#             */
/*   Updated: 2023/07/26 14:59:16 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
ft_init_mutex

--init mutex variables for after use.
	-philo left an right forks
	-is_eating bool
	-print_msg for printing messaghes with a thread
--pthread_mutex_init()
	-return 0 if it was successfull
	-return other values if it wasn't successfull
*/
int	ft_init_mutex(t_data *data)
{
	int	i;
	int	np;

	i = -1;
	np = data->n_philo;
	data->fork = (pthread_mutex_t *)malloc(np * sizeof(pthread_mutex_t));
	if (!data->fork)
		return (FALSE);
	while (++i < data->n_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (FALSE);
	}
	data->print_msg = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(data->print_msg, NULL))
		return (FALSE);
	return (TRUE);
}

void	ft_philo_is_eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->fork[philo->left_fork]);
	ft_print_msg(data, "take left fork", philo->p_id);
	pthread_mutex_lock(&data->fork[philo->rigth_fork]);
	ft_print_msg(data, "take right fork", philo->p_id);
	pthread_mutex_lock(philo->is_eating);
	philo->last_meal = ft_get_timestamp();
	pthread_mutex_unlock(philo->is_eating);
	ft_print_msg(data, "is eating", philo->p_id);
	ft_sleep(data->eat_time, data);
	pthread_mutex_lock(philo->is_eating);
	philo->times_eat++;
	pthread_mutex_unlock(philo->is_eating);
	pthread_mutex_unlock(&data->fork[philo->left_fork]);
	pthread_mutex_unlock(&data->fork[philo->rigth_fork]);
}

void	*ft_start_r(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *)v_philo;
	if (philo->p_id % 2)
	{
		ft_print_msg(philo->data, "is thinking", philo->p_id);
		ft_sleep(philo->data->eat_time, philo->data);
	}
	while (philo->data->dead == FALSE)
	{
		ft_philo_is_eating(philo);
		ft_print_msg(philo->data, "is sleeping", philo->p_id);
		ft_sleep(philo->data->sleep_time, philo->data);
		ft_print_msg(philo->data, "is thinking", philo->p_id);
	}
	return (NULL);
}

int	ft_start(t_data *data)
{
	int		i;
	t_philo	**philo;

	philo = data->philo;
	data->dead = FALSE;
	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_create(&philo[i]->thread, NULL, ft_start_r, philo[i]))
			return (FALSE);
		i++;
	}
	ft_routine_finish(data, philo);
	ft_free_all(data);
	return (TRUE);
}
