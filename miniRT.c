/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:16:22 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/17 19:33:45 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main(int argc, char **argv)
{
	t_vars	*vars;

	(void)argc;
	(void)argv;
	vars = 0;
	if (init(&vars) || !vars)
		exit_prog(0, vars);
	set_hooks(vars);
	mlx_loop(vars->mlx);
	exit_prog(0, vars);
	return (EXIT_SUCCESS);
}
