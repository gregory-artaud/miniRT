/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:52:08 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 14:57:21 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"

void	bmp_pixel_put(t_bmp *bmp, int c)
{
	t_list	*new;
	int		*pxl;

	pxl = malloc(sizeof(int));
	if (!pxl)
		return ;
	*pxl = c;
	new = ft_lstnew(pxl);
	ft_lstadd_front(&(bmp->pxl), new);
	return ;
}
