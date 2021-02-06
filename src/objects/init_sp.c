/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:40:38 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/05 19:01:25 by gartaud          ###   ########lyon.fr   */
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

t_vect	*intersect_sp2(t_ray *r, double b, double c)
{
	t_vect	*v;
	double	t;

	if (!solve_quadratic(1, b, c, &t))
		return (NULL);
	v = v_mult(t, r->dir);
	normalize(v);
	return (v);
}

t_vect	*intersect_sp(t_ray *ray, t_sphere *sp)
{
	double	b;
	double	c;
	double	r_pos_ln;
	double	sp_pos_ln;
	t_vect	*tmp;

	if (!ray || !sp)
		return (0);
	r_pos_ln = v_length(ray->pos);
	sp_pos_ln = v_length(sp->pos);
	tmp = v_minus(ray->pos, sp->pos);
	b = 2 * v_dot(ray->dir, tmp);
	c = r_pos_ln * r_pos_ln;
	c += sp_pos_ln * sp_pos_ln;
	c -= sp->diameter * sp->diameter / 4;
	c -= 2 * v_dot(ray->pos, sp->pos);
	free(tmp);
	return (intersect_sp2(ray, b, c));
}

t_vect	*get_normal_sp(t_vect *hit, t_sphere *sp)
{
	t_vect	*n;

	n = v_minus(hit, sp->pos);
	normalize(n);
	return (n);
}
