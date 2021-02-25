/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 18:22:16 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/25 18:35:03 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_circle		*init_ci(t_vect *pos, t_vect *ori, double radius, t_vect *color)
{
	t_circle	*ci;

	if (!(ci = malloc(sizeof(t_circle))))
		return (NULL);
	ci->pl = init_pl(pos, ori, color);
	if (!(ci->pl))
	{
		free(ci);
		return (NULL);
	}
	ci->radius = radius;
	return (ci);
}

void			free_ci(t_circle *ci)
{
	if (!ci)
		return ;
	free_pl(ci->pl);
	free(ci);
	return ;
}

double			intersect_ci(t_ray *ray, t_circle *ci)
{
	double	t;
	double	d;
	t_vect	*hit;
	t_vect	*to_center;

	t = intersect_pl(ray, ci->pl);
	if (t >= INFINITY)
		return (INFINITY);
	hit = dup_vect(ray->pos);
	v_fadd(hit, v_mult(t, ray->dir));
	to_center = v_minus(hit, ci->pl->pos);
	d = v_length(to_center);
	free(to_center);
	free(hit);
	if (d <= ci->radius)
		return (t);
	return (INFINITY);
}

t_vect			*get_normal_ci(t_ray *ray, t_vect *hit, t_circle *ci)
{
	return (get_normal_pl(ray, hit, ci->pl));
}

int				is_circle(t_object *obj)
{
	return (!ft_memcmp(obj->id, "ci", 3));
}
