/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:06:24 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/18 14:42:38 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		key_pressed(int keycode, t_mlx *vars)
{
	if (keycode == LX_KEY_ESC || keycode == MC_KEY_ESC)
		exit_prog(keycode, vars);
	return (0);
}
