/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:06:13 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 15:16:45 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_triangle	*init_tr(t_vect *p1, t_vect *p2, t_vect *p3, t_vect *color)
{
	t_triangle	*tr;

	tr = (t_triangle *)malloc(sizeof(t_triangle));
	if (!tr)
		return (NULL);
	tr->p1 = p1;
	tr->p2 = p2;
	tr->p3 = p3;
	tr->plan = find_plane(p1, p2, p3, color);
	return (tr);
}

void	free_tr(t_triangle *tr)
{
	if (!tr)
		return ;
	free_pl(tr->plan);
	free(tr->p1);
	free(tr->p2);
	free(tr->p3);
	free(tr);
	return ;
}

double	intersect_tr(t_ray *ray, t_triangle *tr)
{
	t_vect	*hit;
	int		is_out;
	double	t;

	is_out = 0;
	t = intersect_pl(ray, tr->plan);
	hit = dup_vect(ray->pos);
	v_fadd(hit, v_mult(t, ray->dir));
	is_out += is_outside(tr->p1, tr->p2, tr->p3, hit);
	is_out += is_outside(tr->p2, tr->p3, tr->p1, hit);
	is_out += is_outside(tr->p3, tr->p1, tr->p2, hit);
	free(hit);
	if (is_out)
		return (INFINITY);
	return (t);
}

t_vect	*get_normal_tr(t_ray *ray, t_vect *hit, t_triangle *tr)
{
	return (get_normal_pl(ray, hit, tr->plan));
}

int	is_triangle(t_object *obj)
{
	return (!ft_memcmp(obj->id, "tr", 3));
}
