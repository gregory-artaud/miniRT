/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bmp_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:38:20 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 14:58:21 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"

t_bfh	*init_bfh(t_scene *scene)
{
	t_bfh	*bfh;
	int		pad;

	bfh = malloc(sizeof(t_bfh));
	if (!bfh)
		return (NULL);
	bfh->type = ft_strdup("BM");
	if (scene->r_w * 3 % 4)
		pad = 4 - (scene->r_w * 3 % 4);
	else
		pad = 0;
	bfh->size = scene->r_h * (scene->r_w * 3 + pad) + 54;
	bfh->reserved = 0;
	bfh->offset = 54;
	return (bfh);
}

t_bih	*init_bih(t_scene *scene)
{
	t_bih	*bih;

	bih = malloc(sizeof(t_bih));
	if (!bih)
		return (NULL);
	bih->size = 40;
	bih->planes = 1;
	bih->bit_count = 24;
	bih->h = scene->r_h;
	bih->w = scene->r_w;
	return (bih);
}

void	free_bfh(t_bfh *bfh)
{
	if (!bfh)
		return ;
	free(bfh->type);
	free(bfh);
	return ;
}

void	free_bih(t_bih *bih)
{
	if (!bih)
		return ;
	free(bih);
	return ;
}

void	free_pxl(void *pxl)
{
	if (!pxl)
		return ;
	free(pxl);
	return ;
}
