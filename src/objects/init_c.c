/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:20:31 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/15 15:35:05 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

void			init_matrix(double matrix[3][3], t_vect *ori)
{
	t_vect	*c;
	t_vect	*s;

	c = v_mult(M_PI, ori);
	s = dup_vect(c);
	v_cos(c);
	v_sin(s);
	matrix[0][0] = c->y * c->z;
	matrix[0][1] = -s->z * c->x + c->z * s->y * s->x;
	matrix[0][2] = s->z * s->x + c->z * s->y * c->x;
	matrix[1][0] = s->z * c->y;
	matrix[1][1] = c->z * c->x + s->z * s->y * s->x;
	matrix[1][2] = -c->z * s->x + s->z * s->y * c->x;
	matrix[2][0] = -s->y;
	matrix[2][1] = c->y * s->x;
	matrix[2][2] = c->y * c->x;
	/*
	matrix[0][0] = c->z;
	matrix[0][1] = -s->z;
	matrix[0][2] = 0;
	matrix[1][0] = s->z;
	matrix[1][1] = c->z;
	matrix[1][2] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
	*/
	free(c);
	free(s);
	return ;
}

t_camera		*init_c(t_vect *pos, t_vect *ori, double fov)
{
	t_camera	*c;

	if (!(c = (t_camera *)malloc(sizeof(t_camera))))
		return (NULL);
	c->pos = pos;
	c->ori = ori;
	c->fov = fov;
	c->is_used = 0;
	init_matrix(c->matrix, c->ori);
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
	return (!ft_memcmp(obj->id, "c", 2));
}
