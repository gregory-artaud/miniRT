/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:02:46 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/22 18:13:41 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int				check_scene(t_data *data)
{
	int		w;
	int		h;

	w = 900;
	h = 600;
	if (data->scene->r_w <= 0 || data->scene->r_h <= 0)
		return (EXIT_FAILURE);
	mlx_get_screen_size(data->mlx->mlx, &w, &h);
	if (data->scene->r_h >= h || data->scene->r_w >= w)
	{
		data->scene->r_h = h;
		data->scene->r_w = w;
	}
	if (!data->scene->ambiant)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void		free_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	free(mlx);
	return ;
}

static void		*init_mlx(t_data *data, int save)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	data->mlx = mlx;
	mlx->mlx = mlx_init();
	if (!mlx->mlx || check_scene(data))
	{
		free_mlx(mlx);
		return (NULL);
	}
	mlx->win = NULL;
	if (!save)
		mlx->win = mlx_new_window(mlx->mlx, data->scene->r_w,
									data->scene->r_h, "miniRT");
	if (!save && !mlx->win)
	{
		free(mlx);
		return (NULL);
	}
	mlx->save = save;
	return (mlx);
}

void			free_data(t_data *data)
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

t_data			*init_data(char *file, int save)
{
	t_data	*data;
	t_mlx	*mlx;
	t_scene	*scene;

	if (!(data = (t_data*)ft_calloc(1, sizeof(t_data))))
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
		if (!(data->bmp = init_bmp(data->scene)))
			return (failure(data));
	return (data);
}
