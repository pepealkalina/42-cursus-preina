/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:54:13 by preina-g          #+#    #+#             */
/*   Updated: 2022/10/12 16:50:44 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	size_t			i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if ((unsigned char)c == s[i])
		{
			return (1);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		return (0);
	}
	return (0);
}

char	*ft_strcpy(char *dest, char *src, int start)
{
	int	i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i + start] = src[i];
		i++;
	}
	dest[i + start] = '\0';
	return (dest);
}
