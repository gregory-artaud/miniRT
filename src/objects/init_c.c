/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:20:31 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/23 22:41:26 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_camera		*init_c(t_vect *pos, t_vect *ori, double fov)
{
	t_camera	*c;

	if (!(c = (t_camera *)malloc(sizeof(t_camera))))
		return (NULL);
	c->pos = pos;
	c->ori = ori;
	c->fov = fov;
	c->is_used = 0;
	return (c);
}

void			free_c(t_camera *c)
{
	free(c->pos);
	free(c->ori);
	free(c);
	return ;
}

int				is_camera(t_object *obj)
{
	if (!obj)
		return (0);
	return (!ft_strncmp(obj->id, "c", 1));
}
