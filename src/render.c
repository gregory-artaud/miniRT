/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:06:42 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/18 14:42:48 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	shade(void)
{
	return ;
}

int		render(t_data *data)
{
	int		x;
	int		y;
	t_ray	*ray;

	x = -1;
	while (++x < data->mlx->win_w)
	{
		y = -1;
		while (++y < data->mlx->win_h)
		{
			ray = get_ray(data->scene->current_cam, x, y);
			if (trace(ray, data->scene))
				shade();
			free(ray);
		}
	}
	return (0);
}
