/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 10:38:18 by nlagache          #+#    #+#             */
/*   Updated: 2016/11/30 09:47:38 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdio.h>

int		read_line(char **buf, int fd)
{
	char	buffer[BUFF_SIZE + 1];
	int		read_bytes;
	char	*tmp;

	read_bytes = 1;
	if (*buf == NULL)
		*buf = ft_strnew(1);
	while ((ft_strstr(*buf, "\n") == 0) && read_bytes != 0)
	{
		if ((read_bytes = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
		buffer[read_bytes] = '\0';
		tmp = *buf;
		*buf = ft_strjoin(*buf, buffer);
		free(tmp);
		ft_memset(buffer, 0, read_bytes);
	}
	return (ft_strlen(*buf));
}

int		check(char **buf, int reader)
{
	if (reader == 0)
	{
		free(*buf);
		return (0);
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static char	*buf[INT_MAX];
	char		*tmp;
	int			reader;
	int			i;

	tmp = NULL;
	if (BUFF_SIZE > MAX_SIZE_BUFFER || BUFF_SIZE <= 0 || fd < 0
		|| fd > INT_MAX || line == NULL)
		return (-1);
	reader = read_line(&buf[fd % 100], fd);
	if (reader == -1)
		return (-1);
	i = 0;
	while (buf[fd][i] != '\0' && buf[fd][i] != '\n')
		i++;
	*line = ft_strndup(buf[fd], i);
	if (buf[fd])
		tmp = buf[fd];
	buf[fd] = ft_strdup(buf[fd] + i + 1);
	free(tmp);
	free(*line);
	if (check(buf, reader) == 0)
		return (0);
	else
		return (1);
}
