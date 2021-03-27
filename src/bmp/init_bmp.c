/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:37:15 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 14:59:05 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"

t_bmp	*init_bmp(t_scene *scene)
{
	t_bmp	*bmp;

	bmp = malloc(sizeof(t_bmp));
	if (!bmp)
		return (NULL);
	bmp->bfh = init_bfh(scene);
	bmp->bih = init_bih(scene);
	bmp->pxl = ft_lstnew(NULL);
	return (bmp);
}

void	free_bmp(t_bmp *bmp)
{
	if (!bmp)
		return ;
	free_bfh(bmp->bfh);
	free_bih(bmp->bih);
	ft_lstclear(&(bmp->pxl), free_pxl);
	free(bmp);
	return ;
}

int	save_img(t_bmp *bmp)
{
	int		fd;

	fd = open(SAVE_FILE, O_RDWR | O_CREAT, ACCESS_RIGHTS);
	if (fd == -1)
		return (EXIT_FAILURE);
	if (export(fd, bmp))
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
