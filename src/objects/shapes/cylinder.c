/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:15:55 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/23 16:07:03 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_cylinder		*init_cy(t_ray *pos_and_ori, double diameter, double height, t_vect *color)
{
	t_cylinder	*cy;
	double		matrix[3][3];

	if (!(cy = malloc(sizeof(t_cylinder))))
		return (NULL);
	cy->pos = dup_vect(pos_and_ori->pos);
	calc_rot(matrix, pos_and_ori->dir);
	cy->ori = init_vect(0, 1, 0);
	apply_matrix(cy->ori, matrix);
	normalize(cy->ori);
	cy->diameter = diameter;
	cy->height = height;
	cy->color = color;
	free_ray(pos_and_ori);
	return (cy);
}

void			free_cy(t_cylinder *cy)
{
	if (!cy)
		return ;
	free(cy->pos);
	free(cy->ori);
	free(cy->color);
	free(cy);
	return ;
}

int				is_cylinder(t_object *obj)
{
		return (!ft_memcmp(obj->id, "cy", 3));
}

t_vect			*calc_u(t_ray *ray, t_cylinder *cy)
{
	t_vect	*u;
	t_vect	*tmp;
	double	dot;

	dot = v_dot(ray->dir, cy->ori);
	tmp = v_mult(dot, cy->ori);
	u = v_minus(ray->dir, tmp);
	free(tmp);
	return (u);
}

t_vect			*calc_v(t_ray *ray, t_cylinder *cy)
{
	t_vect	*v;
	t_vect	*tmp;
	t_vect	*diff;
	double	dot;

	diff = v_minus(ray->pos, cy->pos);
	dot = v_dot(diff, cy->ori);
	tmp = v_mult(dot, cy->ori);
	v = v_minus(diff, tmp);
	free(diff);
	free(tmp);
	return (v);
}

double			calc_abc(double *a, double *b, t_cylinder *cy, t_ray *ray)
{
	t_vect	*u;
	t_vect	*v;
	double	c;

	u = calc_u(ray, cy);
	v = calc_v(ray, cy);
	*a = v_length(u) * v_length(u);
	*b = 2 * v_dot(u, v);
	c = v_length(v) * v_length(v) - ((cy->diameter * cy->diameter) / 4.0);
	free(u);
	free(v);
	return (c);
}

double			intersect_cy(t_ray *ray, t_cylinder *cy)
{
	double	a;
	double	b;
	double	c;
	double	t;
	int		do_intersect;

	c = calc_abc(&a, &b, cy, ray);
	t = INFINITY;
	do_intersect = solve_quadratic(a, b, c, &t);
	if (!do_intersect)
		return (INFINITY);
	//printf("intersect !\n");
	return (t);
}

t_vect			*get_normal_cy(t_ray *ray, t_vect *hit, t_cylinder *cy)
{
	(void)ray;
	(void)hit;
	(void)cy;
	return (init_vect(0, 0, 0));
}
