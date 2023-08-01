/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:42:06 by preina-g          #+#    #+#             */
/*   Updated: 2023/07/26 15:09:16 by preina-g         ###   ########.fr       */
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

typedef struct s_philo
{
	int				p_id;
	int				rigth_fork;
	int				left_fork;
	int				times_eat;
	long long		last_meal;
	pthread_t		thread;
	pthread_mutex_t	*is_eating;
	struct s_data	*data;
}t_philo;

/*
	n_philo: number of philosophers
	die_time: time to die
	eat_time: time to eat
	sleep_time: time to sleep
	n_times_each_philosopher_must_eat: number of times each philosopher must eat
	fork: mutex for each fork, lock when a philosopher take a fork
	is_eating: mutex for each philosopher
			   lock when a philosopher is eating, unlock when he finish eating
	
*/
typedef struct s_data
{
	int				n_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				n_eats;
	int				eated_times;
	int				dead;
	long long		timestamp;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print_msg;
	t_philo			**philo;
}t_data;

int			ft_atoi(const char *str);
int			ft_arg_parser(const char **argv, t_data *data);
int			ft_init(t_data *data);
long long	ft_get_timestamp(void);
int			ft_init_mutex(t_data *data);
void		ft_print_msg(t_data *data, const char *msg, int philo_id);
void		*ft_start_r(void *v_philo);
int			ft_start(t_data *data);
void		ft_sleep(long long time, t_data *data);
time_t		ft_diff(time_t past, time_t pre);
void		ft_routine_finish(t_data *data, t_philo **philo);
void		ft_free_all(t_data *data);

#endif