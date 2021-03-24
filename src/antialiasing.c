/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:03:03 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/24 10:55:43 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_vect			***init_pixels(t_data *data)
{
	t_vect	***p;
	int		i;
	int		s_w;
	int		s_h;

	s_w = data->scene->r_w * SAMPLING;
	s_h = data->scene->r_h * SAMPLING;
	p = malloc(sizeof(t_vect **) * s_w);
	if (!p)
		return (NULL);
	i = -1;
	while (++i < s_w)
		p[i] = malloc(sizeof(t_vect *) * s_h);
	return (p);
}

void			free_px(t_vect ***px, t_data *data)
{
	int		s_w;
	int		s_h;
	int		i;
	int		j;

	s_w = data->scene->r_w * SAMPLING;
	s_h = data->scene->r_h * SAMPLING;
	i = 0;
	while (i < s_w)
	{
		j = -1;
		while (++j < s_h)
			free(px[i][j]);
		free(px[i]);
		i++;
	}
	free(px);
	return ;
}

t_vect			*average(t_vect ***px, int x, int y, t_data *data)
{
	t_vect	*sum;
	t_vect	*res;
	int		i;
	int		j;

	(void)data;
	sum = init_vect(0, 0, 0);
	i = -1;
	while (++i < SAMPLING)
	{
		j = -1;
		while (++j < SAMPLING)
			v_add_v(sum, px[x + i][y + j]);
	}
	res = v_mult(1.0 / (SAMPLING * SAMPLING), sum);
	free(sum);
	return (res);
}

void			draw_pixels(t_vect ***px, t_data *data)
{
	t_vect	*c;
	int		x;
	int		y;
	int		s_w;
	int		s_h;

	s_w = data->scene->r_w;
	s_h = data->scene->r_h;
	y = 0;
	while (y < s_h)
	{
		x = s_w;
		while (x-- > 0)
		{
			c = average(px, x, y, data);
			draw(data, x, y, c);
		}
		y++;
	}
}

int				antialiasing(t_data *data)
{
	int		x;
	int		y;
	t_ray	*r;
	t_vect	*c;
	t_vect	***pixels;

	if (!data || SAMPLING <= 0)
		return (EXIT_FAILURE);
	pixels = init_pixels(data);
	y = -1;
	while (++y < data->scene->r_h * SAMPLING)
	{
		x = data->scene->r_w * SAMPLING;
		while (x-- > 0)
		{
			r = gen_primary_ray(x, y, data);
			c = trace(r, data->scene, MIRROR_DEPTH);
			pixels[x][y] = c;
			free_ray(r);
		}
		print_progress(y, data->scene->r_h);
	}
	draw_pixels(pixels, data);
	free_px(pixels, data);
	return (EXIT_SUCCESS);
}
