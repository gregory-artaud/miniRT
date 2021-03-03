/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:10:29 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/03 15:43:09 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_vect	*obj_get_color(t_object *obj)
{
	t_vect	*tmp;

	tmp = NULL;
	if (!obj)
		return (NULL);
	if (is_sphere(obj))
		tmp = ((t_sphere *)obj->obj)->color;
	if (is_plane(obj))
		tmp = ((t_plane *)obj->obj)->color;
	if (is_square(obj))
		tmp = ((t_square *)obj->obj)->pl->color;
	if (is_triangle(obj))
		tmp = ((t_triangle *)obj->obj)->plan->color;
	if (is_circle(obj))
		tmp = ((t_circle *)obj->obj)->pl->color;
	return (dup_vect(tmp));
}

int		c_to_hex(t_vect *c)
{
	int		hex;

	if (!c)
		return (0);
	if (c->x < 0 || c->x > 255 ||
		c->y < 0 || c->y > 255 ||
		c->z < 0 || c->z > 255)
		return (0x0);
	hex = (int)floor(c->x);
	hex = hex << 8;
	hex += (int)floor(c->y);
	hex = hex << 8;
	hex += (int)floor(c->z);
	return (hex);
}

int		solve_quadratic(double a, double b, double c, double *sol)
{
	double d;

	d = b * b - 4 * a * c;
	if (d < 0)
		return (0);
	*sol = (-b - sqrt(d)) / (2 * a);
	if (*sol <= 0)
		*sol = (-b + sqrt(d)) / (2 * a);
	if (*sol <= 0)
		return (0);
	return (1);
}

void	put_in_range(t_vect *u, double min, double max)
{
	u->x = floor(fmax(fmin(u->x, max), min));
	u->y = floor(fmax(fmin(u->y, max), min));
	u->z = floor(fmax(fmin(u->z, max), min));
	return ;
}

t_vect	*extract_vect(char *s)
{
	char	**values;
	int		length;
	t_vect	*u;

	if (!s)
		return (NULL);
	values = ft_split(s, ',');
	length = ft_arrlen(values);
	if (length != 3)
	{
		ft_free_strarray(values);
		return (NULL);
	}
	u = init_vect(0, 0, 0);
	u->x = ft_atof(values[0]);
	u->y = ft_atof(values[1]);
	u->z = ft_atof(values[2]);
	ft_free_strarray(values);
	return (u);
}
