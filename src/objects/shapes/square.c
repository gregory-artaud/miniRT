/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 18:13:40 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/25 00:35:41 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_square		*init_sq(t_vect *pos, t_vect *ori, double size, t_vect *color)
{
	t_square	*sq;

	if (!(sq = (t_square *)malloc(sizeof(t_square))))
		return (NULL);
	if (!(sq->pl = init_pl(pos, ori, color)))
	{
		free(sq);
		return (NULL);
	}
	sq->size = size;
	return (sq);
}

void			free_sq(t_square *sq)
{
	if (!sq)
		return ;
	free_pl(sq->pl);
	free(sq);
	return ;
}

double			intersect_sq(t_ray *ray, t_square *sq)
{
	double	t;
	t_vect	*tmp;
	t_vect	*hit;
	double	edge;

	t = intersect_pl(ray, sq->pl);
	hit = dup_vect(ray->pos);
	v_fadd(hit, v_mult(t, ray->dir));
	tmp = v_minus(hit, sq->pl->pos);
	free(hit);
	edge = sq->size / 2.0;
	if (fabs(tmp->x) < edge && fabs(tmp->y) < edge && fabs(tmp->z) < edge)
	{
		free(tmp);
		return (t);
	}
	free(tmp);
	return (INFINITY);
}

t_vect			*get_normal_sq(t_ray *ray, t_vect *hit, t_square *sq)
{
	return (get_normal_pl(ray, hit, sq->pl));
}

int				is_square(t_object *obj)
{
	return (!ft_memcmp(obj->id, "sq", 3));
}
