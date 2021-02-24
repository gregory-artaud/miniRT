/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:06:24 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/24 16:57:54 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	set_hooks(t_data *data)
{
	if (!data->mlx->win)
		return ;
	mlx_hook(data->mlx->win, KeyPress, KeyPressMask, key_pressed, data);
	mlx_hook(data->mlx->win, ClientMessage, ButtonReleaseMask, exit_prog, data);
	return ;
}

int		key_pressed(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit_prog(data);
	if (keycode == KEY_NEXT_CAM)
		next_cam(data);
	return (0);
}

int		exit_prog(t_data *data)
{
	if (data)
		free_data(data);
	exit(EXIT_SUCCESS);
	return (0);
}
