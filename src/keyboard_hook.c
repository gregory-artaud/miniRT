/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:06:24 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/15 20:06:49 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		key_pressed(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit_prog(data);
	if (keycode == KEY_NEXT_CAM)
		next_cam(data);
	return (0);
}
