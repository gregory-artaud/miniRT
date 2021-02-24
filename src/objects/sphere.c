/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:40:38 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/23 19:15:51 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_sphere		*init_sp(t_vect *pos, double diameter, t_vect *color)
{
	t_sphere	*sp;

	if (!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sp->pos = pos;
	sp->diameter = diameter;
	sp->color = color;
	return (sp);
}

void			free_sp(t_sphere *sp)
{
	free(sp->pos);
	free(sp->color);
	free(sp);
	return ;
}

double			intersect_sp(t_ray *ray, t_sphere *sp)
{
	double	b;
	double	c;
	double	i;
	double	k;
	t_vect	*tmp;

	if (!ray || !sp)
		return (0);
	i = v_length(ray->pos);
	k = v_length(sp->pos);
	tmp = v_minus(ray->pos, sp->pos);
	b = 2 * v_dot(ray->dir, tmp);
	c = i * i;
	c += k * k;
	c -= sp->diameter * sp->diameter / 4;
	c -= 2 * v_dot(ray->pos, sp->pos);
	free(tmp);
	if (!solve_quadratic(1, b, c, &i))
		return (INFINITY);
	return (i);
}

t_vect			*get_normal_sp(t_ray *ray, t_vect *hit, t_sphere *sp)
{
	t_vect	*n;
	t_vect	*to_center;

	to_center = v_minus(sp->pos, ray->pos);
	n = v_minus(hit, sp->pos);
	if (v_length(to_center) < sp->diameter)
	{
		n->x *= -1;
		n->y *= -1;
		n->z *= -1;
	}
	normalize(n);
	free(to_center);
	return (n);
}

int				is_sphere(t_object *obj)
{
	return (!ft_memcmp(obj->id, "sp", 3));
}
