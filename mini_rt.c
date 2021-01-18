/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:16:22 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/18 14:42:58 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	error(char *err)
{
	ft_printf(err);
	exit(EXIT_FAILURE);
}

void	run(t_data *data)
{
	set_hooks(data);
	mlx_loop(data->mlx->mlx);
	exit_prog(MC_KEY_ESC, data->mlx);
}

int		main(int argc, char **argv)
{
	t_data	*data;

	if (!(data = init_data()))
		return (EXIT_FAILURE);
	if (argc == 2 || argc == 3)
	{
		if (!(data->scene = init_scene(argv[1])))
			error("Invalid .rt file.\n");
		if (argc == 3)
		{
			if (ft_memcmp(argv[2], "-save", 6))
			{
				free_scene(data->scene);
				error("Wrong option.\nusage : ./miniRT file.rt [-save]\n");
			}
			else
				data->mlx->save = 1;
		}
		run(data);
	}
	if (argc < 2)
		error("Missing argument.\nusage : ./miniRT file.rt [-save]\n");
	if (argc > 3)
		error("Too many argument.\nusage : ./miniRT file.rt [-save]\n");
	return (EXIT_SUCCESS);
}
