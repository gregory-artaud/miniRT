/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:17:05 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/18 15:35:22 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"

int		write_header(int fd, t_bmp *bmp)
{
	int		err;
	char	*zeros;

	if (!(zeros = malloc(sizeof(char) * 24)))
		return (EXIT_FAILURE);
	ft_bzero(zeros, 24);
	err = 0;
	err += (write(fd, bmp->bfh->type, 2) < 0);
	err += (write(fd, &(bmp->bfh->size), 4) < 0);
	err += (write(fd, &(bmp->bfh->reserved), 4) < 0);
	err += (write(fd, &(bmp->bfh->offset), 4) < 0);
	err += (write(fd, &(bmp->bih->size), 4) < 0);
	err += (write(fd, &(bmp->bih->w), 4) < 0);
	err += (write(fd, &(bmp->bih->h), 4) < 0);
	err += (write(fd, &(bmp->bih->planes), 2) < 0);
	err += (write(fd, &(bmp->bih->bit_count), 2) < 0);
	err += (write(fd, zeros, 24) < 0);
	free(zeros);
	return (err);
}

int		write_image(int fd, t_bmp *bmp)
{
	int		nb_bytes;
	t_list	*node;
	int		pxl;
	int		i;
	char	*map;

	nb_bytes = bmp->bih->h * bmp->bih->w * 4;
	if (!(map = malloc(sizeof(char) * nb_bytes)))
		return (EXIT_FAILURE);
	ft_bzero(map, nb_bytes);
	i = 0;
	node = bmp->pxl;
	while (node && node->content)
	{
		pxl = *((int *)node->content);
		map[i++] = (pxl & 255);
		map[i++] = (pxl & 255 << 8) >> 8;
		map[i++] = (pxl & 255 << 16) >> 16;
		map[i++] = 0;
		//printf("%2.2d %2.2d %2.2d\n", map[i - 4], map[i - 3], map[i - 2]);
		node = node->next;
	}
	i = write(fd, map, nb_bytes);
	free(map);
	return (i == -1);
}

int		export(int fd, t_bmp *bmp)
{
	int	err;

	err = 0;
	err += write_header(fd, bmp);
	err += write_image(fd, bmp);
	return (err);
}
