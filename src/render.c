/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:06:42 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/02 18:37:52 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		solve_quadratic(double a, double b, double c, double *sol)
{
	double d;

	d = b * b - 4 * a * c;
	if (d < 0)
		return (0);
	*sol = (-b - sqrt(d)) / (2 * a);
	return (1);
}

t_vect	*get_intersection(t_ray *r, double b, double c)
{
	t_vect	*v;
	double	t;

	if (!solve_quadratic(1, b, c, &t))
		return (NULL);
	v = v_mult(t, r->dir);
	normalize(v);
	return (v);
}

t_vect	*intersect_sp(t_ray *ray, t_sphere *sp)
{
	double	b;
	double	c;
	double	r_pos_ln;
	double	sp_pos_ln;
	t_vect	*tmp;

	if (!ray || !sp)
		return (0);
	r_pos_ln = v_length(ray->pos);
	sp_pos_ln = v_length(sp->pos);
	tmp = v_minus(ray->pos, sp->pos);
	b = 2 * v_dot(ray->dir, tmp);
	c = r_pos_ln * r_pos_ln;
	c += sp_pos_ln * sp_pos_ln;
	c -= sp->diameter * sp->diameter / 4;
	c -= 2 * v_dot(ray->pos, sp->pos);
	free(tmp);
	return (get_intersection(ray, b, c));
}

t_vect	*intersect(t_ray *ray, t_list *lst, t_object **obj)
{
	t_list		*node;
	t_object	*tmp;
	t_vect		*hit;

	node = lst;
	while (node && node->content)
	{
		tmp = (t_object *)(node->content);
		if (!ft_memcmp(tmp->id, "sp", 3))
			if ((hit = intersect_sp(ray, (t_sphere *)tmp->obj)))
			{
				*obj = tmp;
				return (hit);
			}
		node = node->next;
	}
	return (0);
}

t_vect	*trace(t_ray *r, t_list *lst)
{
	t_vect		*c;
	t_vect		*hit;
	t_object	*obj;

	//c = init_vect(0, 0, 0);
	hit = intersect(r, lst, &obj);
	if (!hit)
		return(init_vect(0, 0, 0));
	c = dup_vect(obj_get_color(obj));
	free(hit);
	return (c);
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
			r = gen_cam_ray(x, y, data);
			if (!r)
				return (EXIT_FAILURE);
			c = trace(r, data->scene->obj);
			mlx_pixel_put(data->mlx->mlx, data->mlx->win, x, y, c_to_hex(c));
			free_ray(r);
			free(c);
		}
	}
	return (EXIT_FAILURE);
}
