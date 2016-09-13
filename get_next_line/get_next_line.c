/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlagache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 10:38:18 by nlagache          #+#    #+#             */
/*   Updated: 2016/02/17 14:00:56 by nlagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

int		read_line(char **buf, int fd)
{
	char	buffer[BUFF_SIZE + 1];
	int		read_bytes;

	read_bytes = 1;
	if (*buf == NULL)
		*buf = ft_strnew(1);
	while ((ft_strstr(*buf, "\n") == 0) && read_bytes != 0)
	{
		if ((read_bytes = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
		buffer[read_bytes] = '\0';
		*buf = ft_strjoin(*buf, buffer);
		ft_memset(buffer, 0, read_bytes);
	}
	return (ft_strlen(*buf));
}

int		get_next_line(int const fd, char **line)
{
	static char	*buf[INT_MAX];
	int			reader;
	int			i;

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
	buf[fd] = ft_strdup(buf[fd] + i + 1);
	if (reader == 0)
	{
		buf[fd] = NULL;
		return (0);
	}
	else
	{
		return (1);
	}
}
