/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:16:18 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/09 18:39:11 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "mini_rt.h"

t_vect	*primary_ray_dir(t_scene *scene, t_camera *c, int x, int y)
{
	t_vect	*dir;
	t_vect	*tmp;
	double	fov;
	double	h;
	double	w;

	h = (double)scene->r_h;
	w = (double)scene->r_w;
	fov = tan(deg2rad(c->fov) / 2);
	tmp = init_vect(0, 0, 0);
	tmp->x = fov * (w / h) *
				((double)x * (2.0 / w) + ((1.0 - 1.0 * w) / w));
	tmp->y = fov * ((double)y * (-2.0 / h) + (1.0 + h) / h);
	tmp->z = -1;
	dir = v_minus(tmp, c->pos);
	// cam2world matrix multiplication
	normalize(dir);
	free(tmp);
	return (dir);
}

t_ray	*gen_primary_ray(int x, int y, t_data *data)
{
	t_vect		*pos;
	t_vect		*dir;
	t_camera	*cam;

	if (!(cam = data->scene->current_cam) ||
		!(pos = dup_vect(cam->pos)))
		return (NULL);
	if (!(dir = primary_ray_dir(data->scene, cam, x, y)))
	{
		free(pos);
		return (NULL);
	}
	return (init_ray(pos, dir));
}

t_ray	*gen_shadow_ray(t_vect *ori, t_vect *target)
{
	t_vect	*dir;
	t_vect	*pos;

	if (!ori || !target)
		return (NULL);
	dir = v_minus(target, ori);
	normalize(dir);
	pos = dup_vect(ori);
	return (init_ray(pos, dir));
}

double	intersect_obj(t_ray *r, t_object *obj)
{
	if (!r || !obj)
		return (INFINITY);
	if (is_sphere(obj))
		return (intersect_sp(r, (t_sphere *)obj->obj));
	return (INFINITY);
}

t_vect	*intersect(t_ray *ray, t_list *lst, t_object **obj)
{
	double		t;
	double		t_min;
	t_list		*node;
	t_object	*tmp;

	*obj = NULL;
	if (!ray)
		return (NULL);
	node = lst;
	t_min = INFINITY;
	t = INFINITY;
	while (node && node->content)
	{
		tmp = (t_object *)node->content;
		if (ray)
			t = intersect_obj(ray, tmp);
		if (t < t_min)
		{
			t_min = t;
			*obj = tmp;
		}
		node = node->next;
	}
	if (!obj)
		return (NULL);
	return (v_mult(t_min, ray->dir));
}
