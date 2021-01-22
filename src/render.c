/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:06:42 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/22 11:46:50 by gartaud          ###   ########lyon.fr   */
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

int		render(t_data *data)
{
	int		x;
	int		y;

	x = -1;
	while (++x < data->scene->r_w)
	{
		y = -1;
		while (++y < data->scene->r_h)
			draw_pixel(x, y, data);
	}
	return (0);
}
