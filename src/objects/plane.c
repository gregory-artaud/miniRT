/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:39:15 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/24 18:19:01 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_plan		*init_pl(t_vect *pos, t_vect *ori, t_vect *color)
{
	t_plan	*pl;
	double	matrix[3][3];

	if (!(pl = malloc(sizeof(t_plan))))
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

void		free_pl(t_plan *pl)
{
	if (!pl)
		return ;
	free(pl->pos);
	free(pl->normal);
	free(pl->color);
	free(pl);
	return ;
}

double		intersect_pl(t_ray *ray, t_plan *pl)
{
	double	denom;
	double	res;
	t_vect	*tmp;

	if (!ray || !pl)
		return (INFINITY);
	denom = v_dot(ray->dir, pl->normal);
	if (fabs(denom) < EPSILON)
		return (INFINITY);
	tmp = v_minus(pl->pos, ray->pos);
	res = v_dot(tmp, pl->normal) / denom;
	free(tmp);
	if (res < 0)
		return (INFINITY);
	return (res);
}

t_vect		*get_normal_pl(t_ray *ray, t_vect *hit, t_plan *pl)
{
	(void)ray;
	(void)hit;
	return (dup_vect(pl->normal));
}

int		is_plane(t_object *obj)
{
	return (!ft_memcmp(obj->id, "pl", 3));
}
