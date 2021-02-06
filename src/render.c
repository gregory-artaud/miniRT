/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:06:42 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/06 16:01:08 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	put_in_range(t_vect *u, double min, double max)
{
	u->x = fmax(fmin(u->x, max), min);
	u->y = fmax(fmin(u->y, max), min);
	u->z = fmax(fmin(u->z, max), min);
	return ;
}

t_vect	*calc_diffuse(t_vect *c, t_vect *shad_ray, t_light *l, t_vect *normal)
{
	t_vect	*tmp;
	t_vect	*res;

	tmp = v_mult(K_D * l->lum * v_dot(shad_ray, normal) / 255, l->color);
	res = v_add(c, tmp);
	free(c);
	free(tmp);
	return (res);
}

t_vect	*calc_specular(t_vect *v, t_vect *normal, t_light *l, t_vect *shad_ray)
{
	t_vect	*h;
	t_vect	*res;

	h = v_bisect(shad_ray, v);
	res = v_mult(K_D * l->lum * pow(v_dot(normal, h), N_S) / 255, l->color);
	free(h);
	return (res);
}

int		is_ray_blocked(t_vect *ray, t_list *lst)
{
	(void)ray;
	(void)lst;
	return (0);
}

t_vect	*calc_light(t_vect *v, t_vect *hit, t_vect *normal, t_scene *scene)
{
	t_vect		*c;
	t_list		*node;
	t_object	*obj;
	t_vect		*shad_ray;
	t_vect		*tmp;

	(void)v;
	node = scene->obj;
	c = v_mult(K_A * scene->ambiant->lum / 255, scene->ambiant->color);
	while (node && node->content)
	{
		obj = (t_object *)node->content;
		if (!ft_memcmp(obj->id, "l", 2))
		{
			shad_ray = v_minus(((t_light *)obj->obj)->pos, hit);
			if (!is_ray_blocked(shad_ray, scene->obj))
			{
				c = calc_diffuse(c, shad_ray, (t_light *)obj->obj, normal);
				tmp = calc_specular(v, normal, (t_light *)obj->obj, shad_ray);
				v_fadd(c, tmp);
			}
		}
		node = node->next;
	}
	return (c);
}

t_vect	*shade(t_ray *r, t_vect *hit, t_object *obj, t_scene *scene)
{
	t_vect	*normal;
	t_vect	*c;
	t_vect	*contrib;
	t_vect	*tmp;
	t_vect	*tmp2;

	normal = get_normal(hit, obj);
	tmp = v_mult(EPSILON, normal);
	tmp2 = v_add(hit, tmp);
	free(tmp);
	free(hit);
	hit = tmp2;
	tmp = v_mult(-1, r->dir);
	contrib = calc_light(tmp, hit, normal, scene);
	free(tmp);
	free(tmp2);
	tmp = obj_get_color(obj);
	//printf("contrib : %lf%%, %lf%%, %lf%%\n", contrib->x * 100,
	//									contrib->y * 100,
	//									contrib->z * 100);	
	c = init_vect(tmp->x * contrib->x, tmp->y * contrib->y,
					tmp->z * contrib->z);
	free(normal);
	free(contrib);
	put_in_range(c, 0, 255);
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
	//c = obj_get_color(obj);
	c = shade(r, hit, obj, scene);
	return (c);
}

int		render(t_data *data)
{
	int		x;
	int		y;
	double	progress;
	t_ray	*r;
	t_vect	*c;

	if (!data)
		return (EXIT_FAILURE);
	progress = 0;
	x = -1;
	while (++x < data->scene->r_w)
	{
		y = -1;
		while (++y < data->scene->r_h)
		{
			r = gen_cam_ray(x, y, data);
			c = trace(r, data->scene);
			//if (c->x != 0.0 || c->y != 0 || c->z != 0)
			//	printf("c : %lf, %lf, %lf\n", c->x, c->y, c->z);
			mlx_pixel_put(data->mlx->mlx, data->mlx->win, x, y, c_to_hex(c));
			free(c);
			free_ray(r);
		}
		progress += 1.0 / (double)data->scene->r_w * 100;
		if (SHOW_PROGRESS)
			printf("%.1lf%%\n", progress);
	}
	return (EXIT_SUCCESS);
}
