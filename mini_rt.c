/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:16:22 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/21 21:29:40 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	error(char *s)
{
	printf(s);
	exit(EXIT_FAILURE);
}

void	run(int save)
{
	t_data	*data;

	if (!(data = init_data()))
		error("Error at initialization.\n");
	data->mlx->save = save;
	set_hooks(data);
	mlx_loop(data->mlx->mlx);
	free_data(data);
	return ;
}

int		main(int argc, char **argv)
{
	int		save;

	save = 0;
	if (argc < 2)
		error("Too few arguments.\n");
	if (argc > 3)
		error("Too many arguments.\n");
	if (argc == 3)
		if (!(save = !ft_memcmp("-save", argv[2], 6)))
			error("Second argument can only be '-save'.\n");
	if (ft_memcmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 4))
		error("First argument must be a valid .rt file.\n");
	run(save);
	return (EXIT_SUCCESS);
}
