/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:06:24 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/17 19:07:09 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
** key_hook entry point
*/
int	key_pressed(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		exit_prog(keycode, vars);
	return (0);
}