/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:34:27 by gregory           #+#    #+#             */
/*   Updated: 2020/12/10 14:42:04 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*remainder[4096];
	int				bytes_read;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	bytes_read = 1;
	while (ft_is_in(remainder[fd], '\n') == -1 && bytes_read)
	{
		if ((bytes_read = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[bytes_read] = 0;
		remainder[fd] = ft_append(remainder[fd], buf);
	}
	free(buf);
	*line = ft_strcdup(remainder[fd], '\n');
	remainder[fd] = ft_remainder(remainder[fd]);
	return (bytes_read != 0);
}
