/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:17:05 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 14:56:52 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"

int	write_header(int fd, t_bmp *bmp)
{
	int		err;
	char	*zeros;

	zeros = malloc(sizeof(char) * 24);
	if (!zeros)
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

void	fill_row(unsigned char *map, long int *i, t_bmp *bmp)
{
	int		w_adjust;
	int		w_bytes;

	w_bytes = bmp->bih->w * 3;
	if (!((w_bytes) % 4))
		return ;
	w_adjust = 4 - (w_bytes % 4) + w_bytes;
	while ((*i % w_adjust) >= w_bytes)
		map[(*i)++] = 0;
	return ;
}

int	write_image(int fd, t_bmp *bmp)
{
	int				nb_bytes;
	t_list			*node;
	int				pxl;
	long int		i;
	unsigned char	*map;

	nb_bytes = bmp->bfh->size - 54;
	map = ft_calloc(nb_bytes, sizeof(unsigned char));
	if (!map)
		return (EXIT_FAILURE);
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

int	export(int fd, t_bmp *bmp)
{
	int	err;

	err = 0;
	err += write_header(fd, bmp);
	err += write_image(fd, bmp);
	return (err);
}
