/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:02:46 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/18 14:42:28 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_scene	*init_scene(char *file)
{
	t_scene	*scene;

	if (!detect_rt(file))
		return (NULL);
	if (!(scene = (t_scene *) malloc(sizeof(t_scene))))
		return (NULL);
	return (scene);
}

t_data	*data_malloc(void)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx = 0;
	data->scene = 0;
	return (data);
}

void	set_hooks(t_data *data)
{
	mlx_hook(data->mlx->win, PR_KEY, MK_PR_KEY, key_pressed, data);
	//mlx_hook(vars->win, CLI_MSG, MK_RE_BTN, exit_prog, vars);
	mlx_hook(data->mlx->win, 17, 1L<<17, exit_prog, data);
	mlx_loop_hook(data->mlx->mlx, render, data);
	return ;
}

t_mlx	*init_mlx(void)
{
	t_mlx	*vars;

	if (!(vars = (t_mlx*) malloc(sizeof(t_mlx))))
		return (NULL);
	if (!(vars->mlx = mlx_init()))
	{
		free(vars->mlx);
		free(vars);
		return (NULL);
	}
	vars->win_w = WIN_W;
	vars->win_h = WIN_H;
	if (!(vars->win = mlx_new_window(vars->mlx, vars->win_w, vars->win_h, WIN_NAME)))
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		free(vars);
		return (NULL);
	}
	vars->save = 0;
	return (vars);
}

t_data	*init_data(void)
{
	t_data	*data;
	t_mlx	*mlx;

	if (!(data = data_malloc()))
		return (NULL);
	if (!(mlx = init_mlx()))
	{
		free(data);
		return (NULL);
	}
	data->mlx = mlx;
	return (data);
}