/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:16:22 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/25 01:59:57 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void		error(char *s)
{
	printf("%s", s);
	exit(EXIT_FAILURE);
}

void		print_matrix(double m[3][3])
{
	int		i;
	int		j;

	i = -1;
	while (++i < 3)
	{
		printf("[ ");
		j = -1;
		while (++j < 3)
			printf("%3.1lf ", m[i][j]);
		printf("]\n");
	}
}

static void	run(int save, char *file)
{
	t_data	*data;

	if (!(data = init_data(file, save)))
		error("Error at initialization.\n");
	set_hooks(data);
	printf("Rendering...\n");
	if (render(data))
		error("Error during rendering.\n");
	printf("Image rendered !\n");
	if (data->mlx->save && save_img(data->bmp))
	{
		free_data(data);
		error("Error while saving image.\n");
	}
	mlx_loop(data->mlx->mlx);
	free_data(data);
	return ;
}

int			main(int argc, char **argv)
{
	int		save;

	save = 0;
	if (argc < 2)
		error("Too few arguments.\n");
	if (argc > 3)
		error("Too many arguments.\n");
	if (argc == 3)
		if (!(save = !ft_memcmp("--save", argv[2], 7)))
			error("Second argument can only be '--save'.\n");
	if (ft_memcmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 4))
		error("First argument must be a valid .rt file.\n");
	run(save, argv[1]);
	return (EXIT_SUCCESS);
}
