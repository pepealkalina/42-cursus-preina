/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:28:41 by preina-g          #+#    #+#             */
/*   Updated: 2023/03/01 18:20:12 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_putnbr(const char *str, long long i)
{
	long long	num;

	num = 0;
	while (str[i] <= '9' && str[i] >= '0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

long long	ft_atoll(const char *str)
{
	int			i;
	long long	nb;
	long long	num;

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
