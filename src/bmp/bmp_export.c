/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:17:05 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/23 20:38:07 by gartaud          ###   ########lyon.fr   */
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

void	fill_row(unsigned char *map, int *i, t_bmp *bmp)
{
	int		w_adjust;

	w_adjust = bmp->bih->w;
	if (w_adjust % 4)
		w_adjust += 4 - (w_adjust % 4);
	printf("w_adjust: %d, w: %d\n", w_adjust, bmp->bih->w);
	while (((*i / 3) % w_adjust) > bmp->bih->w)
		ft_bzero(map + (*i)++, 3);
	return ;
}

int		write_image(int fd, t_bmp *bmp)
{
	int				nb_bytes;
	t_list			*node;
	int				pxl;
	int				i;
	unsigned char	*map;

	nb_bytes = bmp->bfh->size - 54;
	if (!(map = malloc(sizeof(unsigned char) * nb_bytes)))
		return (EXIT_FAILURE);
	ft_bzero(map, nb_bytes);
	i = 0;
	node = bmp->pxl;
	while (node && node->content)
	{
		pxl = *((int *)node->content);
		map[i++] = (pxl & 255);
		map[i++] = (pxl & (255 << 8)) >> 8;
		map[i++] = (pxl & (255 << 16)) >> 16;
		fill_row(map, &i, bmp);
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
