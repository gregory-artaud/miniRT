/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:06:42 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/09 20:47:53 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	print_progress(int x, int end)
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

void	put_in_range(t_vect *u, double min, double max)
{
	u->x = fmax(fmin(u->x, max), min);
	u->y = fmax(fmin(u->y, max), min);
	u->z = fmax(fmin(u->z, max), min);
	return ;
}

t_vect	*calc_diffuse(t_ray *shad_ray, t_light *l, t_vect *normal)
{
	double	dot;
	t_vect	*tmp;
	double	to_light;

	tmp = v_minus(l->pos, shad_ray->pos);
	to_light = v_length(tmp);
	to_light = l->lum / (to_light * to_light);
	dot = fmax(0, v_dot(normal, shad_ray->dir));
	return (v_mult(K_D * dot * l->lum * to_light / 255.0, l->color));
}

t_vect	*calc_specular(t_ray *shad_ray, t_vect *v, t_vect *normal, t_light *l)
{
	(void)v;
	(void)normal;
	(void)l;
	(void)shad_ray;
	return (NULL);
}

t_vect	*calc_ambiant(t_light *l)
{
	if (!l)
		return (NULL);
	return (v_mult(K_A * l->lum / 255.0, l->color));
}

int		is_ray_blocked(t_ray *ray, t_list *lst)
{
	t_vect		*tmp;
	t_object	*obj;

	obj = NULL;
	tmp = intersect(ray, lst, &obj);
	if (!obj || !tmp)
		return (0);
	free(tmp);
	return (1);
}

t_vect	*calc_diff_spec(t_ray *ray, t_ray *shad_ray, t_vect *normal, t_light *l)
{
	t_vect	*v;
	t_vect	*res;

	v = v_mult(-1, ray->dir);
	res = calc_diffuse(shad_ray, l, normal);
	free(v);
	return (res);
}

t_vect	*parse_lights(t_ray *ray, t_vect *hit, t_vect *normal, t_scene *scene)
{
	t_vect		*l;
	t_vect		*tmp;
	t_list		*node;
	t_object	*current;
	t_ray		*shad_ray;

	l = calc_ambiant(scene->ambiant);
	node = scene->obj;
	while (node && node->content)
	{
		current = (t_object *)node->content;
		tmp = NULL;
		if (is_light(current))
		{
			shad_ray = gen_shadow_ray(hit, ((t_light *)current->obj)->pos);
			if (!is_ray_blocked(shad_ray, scene->obj))
				tmp = calc_diff_spec(ray, shad_ray, normal,
									(t_light *)current->obj);
			free_ray(shad_ray);
		}
		v_fadd(l, tmp);
		node = node->next;
	}
	return (l);
}

t_vect	*shade(t_ray *r, t_vect *hit, t_object *obj, t_scene *scene)
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
	//printf("c : %lf, %lf, %lf\n", c->x, c->y, c->z);
	return (c);
}

t_vect	*trace(t_ray *r, t_scene *scene)
{
	t_vect		*c;
	t_vect		*hit;
	t_object	*obj;

	if (!r)
		return (init_vect(0, 0, 0));
	hit = intersect(r, scene->obj, &obj);
	if (!hit)
		return(init_vect(0, 0, 0));
	c = shade(r, hit, obj, scene);
	free(hit);
	return (c);
}

void	draw(t_data *data, int x, int y, t_vect *c)
{
	if (!c)
		return ;
	mlx_pixel_put(data->mlx->mlx, data->mlx->win, x, y, c_to_hex(c));
	free(c);
	return ;
}

int		render(t_data *data)
{
	int		x;
	int		y;
	t_ray	*r;
	t_vect	*c;

	if (!data)
		return (EXIT_FAILURE);
	x = -1;
	while (++x < data->scene->r_w)
	{
		y = -1;
		while (++y < data->scene->r_h)
		{
			r = gen_primary_ray(x, y, data);
			c = trace(r, data->scene);
			draw(data, x, y, c);
			free_ray(r);
		}
		print_progress(x, data->scene->r_w);
	}
	return (EXIT_SUCCESS);
}
