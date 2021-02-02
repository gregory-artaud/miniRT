/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:16:18 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/02 18:36:16 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "mini_rt.h"

t_vect	*get_cam_dir(t_scene *scene, t_camera *c, int x, int y)
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

t_ray	*gen_cam_ray(int x, int y, t_data *data)
{
	t_vect		*pos;
	t_vect		*dir;
	t_camera	*cam;

	if (!(cam = data->scene->current_cam) ||
		!(pos = dup_vect(cam->pos)))
		return (NULL);
	if (!(dir = get_cam_dir(data->scene, cam, x, y)))
	{
		free(pos);
		return (NULL);
	}
	return (init_ray(pos, dir));
}
