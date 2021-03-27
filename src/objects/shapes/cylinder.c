/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:15:55 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 15:31:40 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_cylinder	*init_cy(t_ray *pos_and_ori, double diameter,
				double height, t_vect *color)
{
	t_cylinder	*cy;
	double		matrix[3][3];

	cy = malloc(sizeof(t_cylinder));
	if (!cy)
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

void	free_cy(t_cylinder *cy)
{
	if (!cy)
		return ;
	free(cy->pos);
	free(cy->ori);
	free(cy->color);
	free(cy);
	return ;
}

int	is_cylinder(t_object *obj)
{
	return (!ft_memcmp(obj->id, "cy", 3));
}

double	intersect_cy(t_ray *ray, t_cylinder *cy)
{
	double	res;
	t_vect	*x;
	t_vect	*y;
	t_vect	*abc;

	if (!ray || !cy)
		return (INFINITY);
	abc = init_vect(0, 0, 0);
	x = cy_get_x(ray, cy);
	y = cy_get_y(ray, cy);
	abc->x = v_dot(x, x);
	abc->y = 2 * v_dot(x, y);
	abc->z = v_dot(y, y) - (cy->diameter * cy->diameter) / 4.0;
	free(x);
	free(y);
	if (!solve_quadratic(abc->x, abc->y, abc->z, &res))
	{
		free(abc);
		return (INFINITY);
	}
	free(abc);
	return (res);
}

t_vect	*get_normal_cy(t_ray *ray, t_vect *hit, t_cylinder *cy)
{
	t_vect	*p;
	t_vect	*v;
	t_vect	*normal;
	double	t;

	v = v_minus(hit, cy->pos);
	t = v_dot(cy->ori, v);
	p = v_mult(t, cy->ori);
	v_add_v(p, cy->pos);
	normal = v_minus(hit, p);
	free(p);
	free(v);
	normalize(normal);
	if (v_dot(normal, ray->dir) > 0)
		(void)v_fmult(-1, normal);
	return (normal);
}
