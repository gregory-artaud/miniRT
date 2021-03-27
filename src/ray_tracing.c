/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:16:18 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 14:41:35 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static t_vect	*primary_ray_dir(t_scene *scene, t_camera *c, int x, int y)
{
	t_vect	*dir;
	t_vect	*tmp;
	double	fov;
	double	h;
	double	w;

	h = (double)scene->r_h;
	w = (double)scene->r_w;
	if (ANTIALIASING)
	{
		h *= SAMPLING;
		w *= SAMPLING;
	}
	fov = tan(c->fov * M_PI / 360.0);
	tmp = init_vect(0, 0, 0);
	tmp->x = fov * (w / h)
		* ((double)x * (2.0 / w) + ((1.0 - 1.0 * w) / w));
	tmp->y = fov * ((double)y * (-2.0 / h) + (1.0 + h) / h);
	tmp->z = -1;
	dir = dup_vect(tmp);
	apply_matrix(dir, c->matrix);
	normalize(dir);
	free(tmp);
	return (dir);
}

t_ray	*gen_primary_ray(int x, int y, t_data *data)
{
	t_vect		*pos;
	t_vect		*dir;
	t_camera	*cam;

	cam = data->scene->current_cam;
	if (cam)
		pos = dup_vect(cam->pos);
	else
		return (NULL);
	if (!pos)
		return (NULL);
	dir = primary_ray_dir(data->scene, cam, x, y);
	if (!dir)
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
