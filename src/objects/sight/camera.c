/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:20:31 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 15:15:24 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_camera	*init_c(t_vect *pos, t_vect *ori, double fov)
{
	t_camera	*c;

	c = (t_camera *)malloc(sizeof(t_camera));
	if (!c)
		return (NULL);
	c->pos = pos;
	c->ori = ori;
	c->fov = fov;
	c->is_used = 0;
	calc_rot(c->matrix, c->ori);
	return (c);
}

void	free_c(t_camera *c)
{
	free(c->pos);
	free(c->ori);
	free(c);
	return ;
}

int	is_camera(t_object *obj)
{
	if (!obj)
		return (0);
	return (!ft_memcmp(obj->id, "c", 2));
}
