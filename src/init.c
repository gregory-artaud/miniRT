/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:02:46 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/17 21:59:21 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	set_hooks(t_vars *vars)
{
	mlx_hook(vars->win, KeyPress, KeyPressMask, key_pressed, vars);
	mlx_hook(vars->win, ClientMessage, ButtonReleaseMask, exit_prog, vars);
	mlx_loop_hook(vars->mlx, render, vars);
	return ;
}

t_vars	*init(void)
{
	t_vars	*vars;

	if (!(vars = (t_vars*) malloc(sizeof(t_vars))))
		return (NULL);
	if (!(vars->mlx = mlx_init()))
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		free(vars);
		return (NULL);
	}
	mlx_get_screen_size(vars->mlx, &(vars->win_w), &(vars->win_h));
	vars->win_w /= 2;
	vars->win_h /= 2;
	if (!(vars->win = mlx_new_window(vars->mlx, vars->win_w, vars->win_h, WIN_NAME)))
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		free(vars);
		return (NULL);
	}
	return (vars);
}