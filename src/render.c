/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:06:42 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/24 01:42:22 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		draw_pixel(int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	(void)data;
	return (0);
}

int		intersect_sp(t_ray *ray, t_sphere *sp)
{
	double	b;
	double	c;
	double	delta;
	double	r_pos_ln;
	double	sp_pos_ln;

	if (!ray || !sp)
		return (0);
	r_pos_ln = v_lenght(ray->pos);
	sp_pos_ln = v_lenght(sp->pos);
	//print_sp(sp);
	//printf("r, sp : %lf, %lf\n", r_pos_ln, sp_pos_ln);
	b = ray->dir->x * (ray->pos->x - sp->pos->x);
	b += ray->dir->y * (ray->pos->y - sp->pos->y);
	b += ray->dir->z * (ray->pos->z - sp->pos->z);
	b *= 2;
	c = r_pos_ln * r_pos_ln;
	c += sp_pos_ln * sp_pos_ln;
	c -= sp->diameter * sp->diameter / 4;
	c -= 2 * v_dot(ray->pos, sp->pos);
	delta = b * b - 4 * c;
	//printf("delta, b, c : %lf, %lf, %lf\n", delta, b, c);
	return (delta >= 0);
}

int		intersect(t_ray *ray, t_list *obj)
{
	t_list		*node;
	int			res;

	res = 0;
	node = obj;
	while (node)
	{
		if (!ft_memcmp(((t_object *)(node->content))->id, "sp", 3))
			return (intersect_sp(ray, (t_sphere *)((t_object *)(node->content))->obj));
		node = node->next;
	}
	return (res);
}

int		render(t_data *data)
{
	int		x;
	int		y;
	t_ray	*r;

	if (!data)
		return (0);
	x = -1;
	while (++x < data->scene->r_w)
	{
		y = -1;
		while (++y < data->scene->r_h)
		{
			r = gen_ray(x, y, data);
			if (r)
			{
				//printf("%d, %d : %lf, %lf, %lf\n", x, y, r->dir->x, r->dir->y, r->dir->z);
				if (intersect(r, data->scene->obj))
					mlx_pixel_put(data->mlx->mlx, data->mlx->win, x, y, 0x00FFFFFF);
				free_ray(r);
			}
		}
	}
	return (0);
}
