/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:06:42 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/24 08:47:04 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void		print_progress(int x, int end)
{
	double	old;
	double	progress;

	old = (double)(x - 1) / (double)end * 100;
	progress = (double)x / (double)end * 100;
	if (old < 10 && progress >= 10)
		printf("%.1lf%%\n", progress);
	else if (old < 25 && progress >= 25)
		printf("%.1lf%%\n", progress);
	else if (old < 50 && progress >= 50)
		printf("%.1lf%%\n", progress);
	else if (old < 75 && progress >= 75)
		printf("%.1lf%%\n", progress);
	else if (old < 90 && progress >= 90)
		printf("%.1lf%%\n", progress);
	else if (old < 95 && progress >= 95)
		printf("%.1lf%%\n", progress);
	return ;
}

static t_vect	*shade(t_ray *r, t_vect *hit, t_object *obj, t_scene *scene)
{
	t_vect	*tmp;
	t_vect	*l;
	t_vect	*c;
	t_vect	*normal;

	if (!obj)
		return (init_vect(0, 0, 0));
	if (!(tmp = obj_get_color(obj)))
		return (init_vect(0, 0, 0));
	normal = get_normal(r, hit, obj);
	translate(hit, EPSILON, normal);
	l = parse_lights(r, hit, normal, scene);
	c = v_vmult(tmp, l);
	free(tmp);
	free(l);
	free(normal);
	return (c);
}

t_vect	*trace(t_ray *r, t_scene *scene, int depth)
{
	t_vect		*c;
	t_vect		*hit;
	t_ray		*reflect;
	double		t;
	t_object	*obj;

	if (!r || depth < 0)
		return (init_vect(0, 0, 0));
	obj = NULL;
	t = intersect(r, scene->obj, &obj);
	if (t == INFINITY)
		return (init_vect(0, 0, 0));
	hit = dup_vect(r->pos);
	v_fadd(hit, v_mult(t, r->dir));
	reflect = NULL;
	if (depth)
		reflect = get_reflect(r, hit, obj);
	c = shade(r, hit, obj, scene);
	v_fadd(c, v_fmult(K_S, trace(reflect, scene, depth - 1)));
	free(hit);
	free_ray(reflect);
	put_in_range(c, 0, 255);
	return (c);
}

void		draw(t_data *data, int x, int y, t_vect *c)
{
	if (!c)
		return ;
	if (!data->mlx->save)
		mlx_pixel_put(data->mlx->mlx, data->mlx->win, x, y, c_to_hex(c));
	else
		bmp_pixel_put(data->bmp, c_to_hex(c));
	free(c);
	return ;
}

int				render(t_data *data)
{
	int		x;
	int		y;
	t_ray	*r;
	t_vect	*c;

	if (ANTIALIASING)
		return (antialiasing(data));
	if (!data)
		return (EXIT_FAILURE);
	y = -1;
	while (++y < data->scene->r_h)
	{
		x = data->scene->r_w;
		while (x-- > 0)
		{
			r = gen_primary_ray(x, y, data);
			c = trace(r, data->scene, MIRROR_DEPTH);
			draw(data, x, y, c);
			free_ray(r);
		}
		print_progress(y, data->scene->r_h);
	}
	return (EXIT_SUCCESS);
}
