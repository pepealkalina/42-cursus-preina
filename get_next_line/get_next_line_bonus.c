/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:54:09 by preina-g          #+#    #+#             */
/*   Updated: 2022/10/12 16:51:23 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char	*ft_read_line(int fd, char *file_rd)
{
	char		*str;
	ssize_t		rd_bytes;

	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	rd_bytes = 1;
	while (rd_bytes != 0 && !ft_strchr(file_rd, '\n'))
	{
		rd_bytes = read(fd, str, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(file_rd);
			free(str);
			return (NULL);
		}
		str[rd_bytes] = '\0';
		file_rd = ft_strjoin(file_rd, str);
	}
	free (str);
	return (file_rd);
}

char	*ft_get_line(char *file_rd)
{
	char	*line;
	int		i;

	i = 0;
	if (!file_rd[i])
		return (NULL);
	while (file_rd[i] && file_rd[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (file_rd[i] && file_rd[i] != '\n')
	{
		line[i] = file_rd[i];
		i++;
	}
	if (file_rd[i] == '\n')
	{
		line[i] = file_rd[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_save_line(char *file_rd)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (file_rd[i] && file_rd[i] != '\n')
		i++;
	if (!file_rd[i])
	{
		free(file_rd);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * ft_strlen(file_rd) - i + 1);
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (file_rd[i])
		line[j++] = file_rd[i++];
	line[j] = '\0';
	free(file_rd);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*file_rd[4096];
	char		*line;

	while (fd < 0 || fd > 4095 || BUFFER_SIZE == 0)
		return (0);
	file_rd[fd] = ft_read_line(fd, file_rd[fd]);
	if (!file_rd[fd])
		return (NULL);
	line = ft_get_line(file_rd[fd]);
	file_rd[fd] = ft_save_line(file_rd[fd]);
	return (line);
}
