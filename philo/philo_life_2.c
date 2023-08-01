/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 11:56:54 by preina-g          #+#    #+#             */
/*   Updated: 2023/07/26 15:03:50 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_routine_finish(t_data *data, t_philo **philo)
{
	int		i;

	ft_sleep(data->die_time, data);
	while (data->dead == FALSE)
	{
		i = -1;
		while (++i < data->n_philo)
		{
			pthread_mutex_lock(philo[i]->is_eating);
			if ((ft_get_timestamp() - philo[i]->last_meal) >= data->die_time)
			{
				ft_print_msg(data, "died", philo[i]->p_id);
				data->dead = TRUE;
			}
			pthread_mutex_unlock(philo[i]->is_eating);
		}
		if (data->dead == TRUE)
			break ;
		i = 0;
		while (i < data->n_philo && data->n_eats != -1
			&& data->philo[i]->times_eat >= data->n_eats)
			i++;
		if (i == data->n_philo)
			data->dead = TRUE;
	}
}

void	ft_free_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		pthread_join(data->philo[i]->thread, NULL);
		pthread_mutex_destroy(data->philo[i]->is_eating);
		pthread_mutex_destroy(&data->fork[i]);
		free(data->philo[i]->is_eating);
		free(data->philo[i]);
	}
	free(data->fork);
	free(data->philo);
	pthread_mutex_destroy(data->print_msg);
	free(data->print_msg);
	free(data);
}

void	ft_init_philo(t_data *data, t_philo *philo, int id)
{
	philo->p_id = id;
	philo->last_meal = 0;
	philo->left_fork = id;
	philo->rigth_fork = (id + 1) % data->n_philo;
	philo->data = data;
	philo->is_eating = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(philo->is_eating, NULL))
		return ;
}

/*ft_init()
	init al the philo variables and threads
*/
int	ft_init(t_data *data)
{
	int	i;

	data->philo = (t_philo **)malloc(data->n_philo * sizeof(t_philo *));
	if (!data->philo)
		return (FALSE);
	i = -1;
	while (++i < data->n_philo)
	{
		data->philo[i] = (t_philo *)malloc(sizeof(t_philo));
		ft_init_philo(data, data->philo[i], i);
	}
	if (ft_init_mutex(data) == FALSE)
		return (FALSE);
	data->timestamp = ft_get_timestamp();
	ft_start(data);
	return (TRUE);
}
