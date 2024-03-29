/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:16:22 by gartaud           #+#    #+#             */
/*   Updated: 2021/04/02 09:02:06 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	error(char *s, t_data *data)
{
	ft_putstr_fd(s, STDERR_FILENO);
	if (data)
		free(data);
	exit(EXIT_FAILURE);
}

static void	run(int save, char *file)
{
	t_data	*data;

	data = init_data(file, save);
	if (!data)
		error("Error at initialization.\n", NULL);
	set_hooks(data);
	printf("Rendering...\n");
	if (render(data))
		error("Error during rendering.\n", data);
	printf("Image rendered !\n");
	if (data->mlx->save && save_img(data->bmp))
		error("Error while saving image.\n", data);
	else if (!data->mlx->save)
		mlx_loop(data->mlx->mlx);
	free_data(data);
	return ;
}

int	main(int argc, char **argv)
{
	int		save;

	save = 0;
	if (argc < 2)
		error("Too few arguments.\n", NULL);
	if (argc > 3)
		error("Too many arguments.\n", NULL);
	if (argc == 3)
	{
		save = !ft_memcmp("--save", argv[2], 7);
		if (!save)
			error("Second argument can only be '--save'.\n", NULL);
	}
	if (ft_memcmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt", 4))
		error("First argument must be a valid .rt file.\n", NULL);
	run(save, argv[1]);
	return (EXIT_SUCCESS);
}
