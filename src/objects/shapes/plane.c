/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:39:15 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/28 23:02:23 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_plane		*init_pl(t_vect *pos, t_vect *ori, t_vect *color)
{
	t_plane	*pl;
	double	matrix[3][3];

	if (!(pl = malloc(sizeof(t_plane))))
		return (NULL);
	pl->pos = pos;
	pl->color = color;
	calc_rot(matrix, ori);
	free(ori);
	ori = init_vect(0, 1, 0);
	apply_matrix(ori, matrix);
	normalize(ori);
	pl->normal = ori;
	return (pl);
}

void		free_pl(t_plane *pl)
{
	if (!pl)
		return ;
	free(pl->pos);
	free(pl->normal);
	free(pl->color);
	free(pl);
	return ;
}

double		intersect_pl(t_ray *ray, t_plane *pl)
{
	double	denom;
	double	res;
	t_vect	*tmp;

	if (!ray || !pl)
		return (INFINITY);
	denom = v_dot(ray->dir, pl->normal);
	if (fabs(denom) == 0.0)
		return (INFINITY);
	tmp = v_minus(pl->pos, ray->pos);
	res = v_dot(tmp, pl->normal) / denom;
	free(tmp);
	if (res < 0)
		return (INFINITY);
	return (res);
}

t_vect		*get_normal_pl(t_ray *ray, t_vect *hit, t_plane *pl)
{
	double	dot;

	(void)hit;
	dot = v_dot(ray->dir, pl->normal);
	if (dot > 0)
		return (v_mult(-1, pl->normal));
	return (dup_vect(pl->normal));
}

int			is_plane(t_object *obj)
{
	return (!ft_memcmp(obj->id, "pl", 3));
}
