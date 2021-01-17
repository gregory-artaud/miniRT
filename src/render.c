/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:06:42 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/17 22:13:26 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		draw_pixel(int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	(void)vars;
	return (0);
}

int		render(t_vars *vars)
{
	int		x;
	int		y;

	x = -1;
	while (++x < vars->win_w)
	{
		y = -1;
		while (++y < vars->win_h)
			draw_pixel(x, y, vars);
	}
	return (0);
}