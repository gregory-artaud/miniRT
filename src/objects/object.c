/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:02:45 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/28 23:45:55 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_object		*init_object(void)
{
	t_object	*obj;

	if (!(obj = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	obj->id = NULL;
	obj->obj = NULL;
	return (obj);
}

void			free_object(void *ptr)
{
	t_object	*obj;

	obj = (t_object *)ptr;
	if (!obj)
		return ;
	if (is_sphere(obj))
		free_sp(obj->obj);
	else if (is_camera(obj))
		free_c(obj->obj);
	else if (is_light(obj))
		free_l(obj->obj);
	else if (is_plane(obj))
		free_pl(obj->obj);
	else if (is_square(obj))
		free_sq(obj->obj);
	else if (is_triangle(obj))
		free_tr(obj->obj);
	else if (is_circle(obj))
		free_ci(obj->obj);
	else if (is_cylinder(obj))
		free_cy(obj->obj);
	free(obj->id);
	free(obj);
	return ;
}

static double	intersect_obj(t_ray *r, t_object *obj)
{
	if (!r || !obj)
		return (INFINITY);
	if (is_sphere(obj))
		return (intersect_sp(r, (t_sphere *)obj->obj));
	if (is_plane(obj))
		return (intersect_pl(r, (t_plane *)obj->obj));
	if (is_square(obj))
		return (intersect_sq(r, (t_square *)obj->obj));
	if (is_triangle(obj))
		return (intersect_tr(r, (t_triangle *)obj->obj));
	if (is_circle(obj))
		return (intersect_ci(r, (t_circle *)obj->obj));
	return (INFINITY);
}

double			intersect(t_ray *ray, t_list *lst, t_object **obj)
{
	double		t;
	double		t_min;
	t_list		*node;
	t_object	*tmp;

	*obj = NULL;
	if (!ray)
		return (INFINITY);
	node = lst;
	t_min = INFINITY;
	t = INFINITY;
	while (node && node->content)
	{
		tmp = (t_object *)node->content;
		t = intersect_obj(ray, tmp);
		if (t < t_min)
		{
			t_min = t;
			*obj = tmp;
		}
		node = node->next;
	}
	if (!obj)
		return (INFINITY);
	return (t_min);
}

t_vect			*get_normal(t_ray *ray, t_vect *hit, t_object *obj)
{
	if (!obj)
		return (NULL);
	if (is_sphere(obj))
		return (get_normal_sp(ray, hit, (t_sphere *)obj->obj));
	if (is_plane(obj))
		return (get_normal_pl(ray, hit, (t_plane *)obj->obj));
	if (is_square(obj))
		return (get_normal_sq(ray, hit, (t_square *)obj->obj));
	if (is_triangle(obj))
		return (get_normal_tr(ray, hit, (t_triangle *)obj->obj));
	if (is_circle(obj))
		return (get_normal_ci(ray, hit, (t_circle *)obj->obj));
	return (NULL);
}
