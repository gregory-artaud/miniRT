/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:16:18 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/24 00:45:36 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "mini_rt.h"

t_vect	*get_dir(t_scene *scene, t_camera *c, int x, int y)
{
	t_vect	*dir;
	double	fov;
	double	iar;
	double	h;
	double	w;

	h = (double)scene->r_h;
	w = (double)scene->r_w;
	fov = tan(deg2rad(c->fov) / 2);
	iar = w / h;
	dir = init_vect(0, 0, 0);
	dir->x = fov * iar *
				((double)x * (2.0 / w) + ((1.0 - 1.0 * w) / w));
	dir->y = fov * ((double)y * (-2.0 / h) + (1.0 + h) / h);
	dir->z = -1;
	dir = minus_vect(dir, c->pos);
	normalize(dir);
	return (dir);
}

t_ray	*gen_ray(int x, int y, t_data *data)
{
	t_vect		*pos;
	t_vect		*dir;
	t_camera	*cam;

	if (!(cam = data->scene->current_cam) ||
		!(pos = dup_vect(cam->pos)) ||
		!(dir = get_dir(data->scene, cam, x, y)))
		return (NULL);
	return (init_ray(pos, dir));
}
