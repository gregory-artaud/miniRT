/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:08:08 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/17 19:08:23 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	exit_prog(int keycode, t_vars *vars)
{
	(void)keycode;
	/*
	** Free all memory here
	*/
	if (vars->mlx && vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	//free(vars->win);
	free(vars->mlx);
	free(vars);
	exit(EXIT_SUCCESS);
	return (0);
}