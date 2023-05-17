/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:40:20 by preina-g          #+#    #+#             */
/*   Updated: 2022/11/30 15:12:55 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

// | is 1 When one bit is 1.
void	ft_signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	c;
	static int	bits = 0;

	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		c |= (1 << bits);
	if (++bits == 8)
	{
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		ft_printf("%c", c);
		bits = 0;
		c = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	s_signal;

	pid = getpid();
	ft_printf(VERDE_T "PID" AMARILLO_T " -> " CYAN_T "%i\n" RESET_COLOR, pid);
	s_signal.sa_sigaction = ft_signal_handler;
	s_signal.sa_flags = SA_SIGINFO;
	ft_printf(MAGENTA_T "Waiting for message ...\n" RESET_COLOR);
	sigaction(SIGUSR1, &s_signal, 0);
	sigaction(SIGUSR2, &s_signal, 0);
	while (1)
		pause();
	return (0);
}
