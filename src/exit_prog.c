/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:08:08 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/18 15:03:38 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		exit_prog(int keycode, t_mlx *vars)
{
	(void)keycode;
	(void)vars;
	exit(EXIT_SUCCESS);
	/*
	if (keycode != LX_KEY_ESC && keycode != MC_KEY_ESC)
		exit(EXIT_SUCCESS);
	*/
	return (0);
}

void	free_scene(t_scene *scene)
{
	(void)scene;
	return ;
}
