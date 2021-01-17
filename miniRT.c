/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:16:22 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/17 21:56:44 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main(int argc, char **argv)
{
	t_vars	*mlx_data;

	(void)argc;
	(void)argv;
	mlx_data = init();
	if (!mlx_data)
		exit_prog(KEY_ESC, mlx_data);
	set_hooks(mlx_data);
	mlx_loop(mlx_data->mlx);
	exit_prog(KEY_ESC, mlx_data);
	return (EXIT_SUCCESS);
}
