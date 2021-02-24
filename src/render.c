/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:06:42 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/24 16:47:48 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void		print_progress(int x, int end)
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
	put_in_range(c, 0, 255);
	free(tmp);
	free(l);
	free(normal);
	return (c);
}

static t_vect	*trace(t_ray *r, t_scene *scene)
{
	t_vect		*c;
	t_vect		*hit;
	double		t;
	t_object	*obj;

	if (!r)
		return (init_vect(0, 0, 0));
	t = intersect(r, scene->obj, &obj);
	hit = dup_vect(r->pos);
	v_fadd(hit, v_mult(t, r->dir));
	if (!hit)
		return (init_vect(0, 0, 0));
	c = shade(r, hit, obj, scene);
	free(hit);
	return (c);
}

static void		draw(t_data *data, int x, int y, t_vect *c)
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

	if (!data)
		return (EXIT_FAILURE);
	y = -1;
	while (++y < data->scene->r_h)
	{
		x = -1;
		while (++x < data->scene->r_w)
		{
			r = gen_primary_ray(x, y, data);
			c = trace(r, data->scene);
			draw(data, x, y, c);
			free_ray(r);
		}
		print_progress(y, data->scene->r_h);
	}
	return (EXIT_SUCCESS);
}
