/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:38:44 by preina-g          #+#    #+#             */
/*   Updated: 2022/11/30 12:18:43 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(char *argument)
{
	int	i;

	i = 0;
	while (argument[i])
	{
		if ((argument[i] >= '0' && argument[i] <= '9'))
			i++;
		else
			return (-1);
	}
	return (0);
}
