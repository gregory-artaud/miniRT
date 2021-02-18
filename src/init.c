/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:02:46 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/18 11:59:54 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	set_hooks(t_data *data)
{
	if (!data->mlx->win)
		return ;
	mlx_hook(data->mlx->win, KeyPress, KeyPressMask, key_pressed, data);
	mlx_hook(data->mlx->win, ClientMessage, ButtonReleaseMask, exit_prog, data);
	//mlx_loop_hook(data->mlx->mlx, render, data);
	return ;
}

void	free_mlx(t_mlx *mlx)
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

void	*init_mlx(t_scene *scene, int save)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx = mlx_init()))
	{
		free_mlx(mlx);
		return (NULL);
	}
	mlx->win = NULL;
	if (!save)
		mlx->win = mlx_new_window(mlx->mlx, scene->r_w, scene->r_h, "miniRT");
	if (!save && !mlx->win)
	{
		free(mlx);
		return (NULL);
	}
	mlx->save = save;
	return (mlx);
}

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

t_data	*init_data(char *file, int save)
{
	t_data	*data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	if (!(data->scene = init_scene()) ||
		fill_scene(data->scene, file) ||
		!(data->mlx = init_mlx(data->scene, save)))
	{
		free_data(data);
		return (NULL);
	}
	data->bmp = NULL;
	if (save)
		if (!(data->bmp = init_bmp(data->scene)))
		{
			free_data(data);
			return (NULL);
		}
	return (data);
}
