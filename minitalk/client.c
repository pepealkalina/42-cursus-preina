/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:40:13 by preina-g          #+#    #+#             */
/*   Updated: 2022/11/30 15:12:46 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	ft_confirm(int signum)
{
	static int	i = 0;

	if (signum == SIGUSR2)
	{
		i++;
	}
	else
		exit(ft_printf(VERDE_T "received chara %i\n" RESET_COLOR, i));
}

void	ft_send_binary(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	int		i;
	char	*conection;

	signal(SIGUSR1, ft_confirm);
	signal(SIGUSR2, ft_confirm);
	if (argc != 3)
	{
		ft_printf(ROJO_T "Invalid arguments\n");
		ft_printf(VERDE_T "Try ./client <PID> <MESSAGE\n>");
		exit(EXIT_FAILURE);
	}
	if (ft_isdigit(argv[1]) == -1)
	{
		ft_printf(ROJO_T "Invalid arguments\n");
		ft_printf(VERDE_T "Try ./client <PID> <MESSAGE>\n");
	}
	else
		pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
		ft_send_binary(argv[2][i++], pid);
	ft_send_binary('\n', pid);
	ft_send_binary('\0', pid);
	return (0);
}
