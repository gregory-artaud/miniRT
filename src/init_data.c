/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:02:46 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 14:52:38 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->scene)
		free_scene(data->scene, free_object);
	if (data->mlx)
		free_mlx(data->mlx);
	if (data->bmp)
		free_bmp(data->bmp);
	free(data);
	return ;
}

static t_data	*failure(t_data *data)
{
	free_data(data);
	return (NULL);
}

t_data	*init_data(char *file, int save)
{
	t_data	*data;
	t_mlx	*mlx;
	t_scene	*scene;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	scene = init_scene();
	data->scene = scene;
	if (!scene || parse_file(data->scene, file))
		return (failure(data));
	mlx = init_mlx(data, save);
	data->mlx = mlx;
	if (!mlx)
		return (failure(data));
	data->bmp = NULL;
	if (save)
	{
		data->bmp = init_bmp(data->scene);
		if (!data->bmp)
			return (failure(data));
	}
	return (data);
}
