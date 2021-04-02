/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssaa_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 07:32:44 by gartaud           #+#    #+#             */
/*   Updated: 2021/04/02 07:33:42 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_vect	***init_pixels(t_data *data)
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

void	free_px(t_vect ***px, t_data *data)
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

t_vect	*average(t_vect ***px, int x, int y)
{
	t_vect	*sum;
	t_vect	*res;
	int		i;
	int		j;

	sum = init_vect(0, 0, 0);
	i = -1;
	while (++i < SAMPLING)
	{
		j = -1;
		while (++j < SAMPLING)
			v_add_v(sum, px[x * SAMPLING + i][y * SAMPLING + j]);
	}
	res = v_mult(1.0 / (SAMPLING * SAMPLING), sum);
	free(sum);
	return (res);
}

void	draw_pixels(t_vect ***px, t_data *data)
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
			c = average(px, x, y);
			draw(data, x, y, c);
		}
		y++;
	}
}

void	init_arg(t_ssaa *arg[NUM_THREAD], t_data *data)
{
	int		i;
	int		start;
	int		end;
	int		interval;
	t_vect	***px;

	px = init_pixels(data);
	interval = data->scene->r_w * SAMPLING / (NUM_THREAD - 1);
	start = 0;
	end = interval;
	i = 0;
	while (i < NUM_THREAD)
	{
		arg[i]->px = px;
		arg[i]->data = data;
		arg[i]->start = start;
		arg[i]->end = end;
		start = end;
		end = ft_min(data->scene->r_w * SAMPLING, end + interval);
		i++;
	}
}
