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



int		intersect(t_ray *ray, t_list *obj)
{
	(void)ray;
	(void)obj;
	return (0);
}

int		render(t_data *data)
{
	int		x;
	int		y;
	t_ray	*r;

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
					mlx_pixel_put(data->mlx->mlx, data->mlx->win, x, y, 0xFFFFFFFF);
				free_ray(r);
			}
		}
	}
	return (0);
}
