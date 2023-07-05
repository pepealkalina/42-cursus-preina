/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:42:06 by preina-g          #+#    #+#             */
/*   Updated: 2023/07/05 09:12:50 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> //printf
# include <stdlib.h> //malloc
# include <unistd.h> //usleep
# include <pthread.h> //pthread
# include <sys/time.h> //timestamp

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0,
}t_bool;

typedef struct s_data
{
	int	n_philo;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	n_times_each_philosopher_must_eat;

}t_arg_data;

typedef struct s_philo
{
	int	p_id;
	int	rigth_fork;
	int	left_fork;
	int	right_fork;
	long long	last_meal;
	pthread_t	thread;
	struct s_data	*data;
}t_philo;

int	ft_atoi(const char *str);
int	ft_arg_parser(const char **argv, t_data *data);

#endif