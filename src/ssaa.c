/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssaa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:03:03 by gartaud           #+#    #+#             */
/*   Updated: 2021/04/02 07:34:01 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	*render_image(void *arg)
{
	int			x;
	int			y;
	t_ray		*r;
	t_vect		*c;
	t_ssaa		*ssaa;

	ssaa = (t_ssaa *)arg;
	y = -1;
	while (++y < ssaa->data->scene->r_h * SAMPLING)
	{
		x = ssaa->end;
		while (x-- > ssaa->start)
		{
			r = gen_primary_ray(x, y, ssaa->data);
			c = trace(r, ssaa->data->scene, MIRROR_DEPTH);
			ssaa->px[x][y] = c;
			free_ray(r);
		}
	}
	return (NULL);
}

int	render_ssaa(t_data *data)
{
	t_ssaa		**arg;
	pthread_t	id[NUM_THREAD];
	int			i;

	if (!data || SAMPLING <= 0)
		return (EXIT_FAILURE);
	arg = malloc(sizeof(t_ssaa *) * NUM_THREAD);
	if (!arg)
		return (EXIT_FAILURE);
	i = -1;
	while (++i < NUM_THREAD)
		arg[i] = malloc(sizeof(t_ssaa));
	init_arg(arg, data);
	i = -1;
	while (++i < NUM_THREAD)
		pthread_create(id + i, NULL, render_image, arg[i]);
	i = -1;
	while (++i < NUM_THREAD)
		pthread_join(id[i], NULL);
	draw_pixels(arg[0]->px, data);
	free_px(arg[0]->px, data);
	free(arg);
	return (EXIT_SUCCESS);
}
