/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:12:27 by gartaud           #+#    #+#             */
/*   Updated: 2021/04/02 09:28:53 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	init_ft_array(int (*f[NB_ID])(t_scene *, char **))
{
	f[0] = set_resolution;
	f[1] = set_ambiant;
	f[2] = add_camera;
	f[3] = add_light;
	f[4] = add_sphere;
	f[5] = add_plane;
	f[6] = add_square;
	f[7] = add_cylinder;
	f[8] = add_triangle;
	f[9] = add_circle;
	return ;
}

int	id_to_int(char	*id)
{
	if (!ft_memcmp(id, R_ID, R_ID_LN))
		return (0);
	else if (!ft_memcmp(id, A_ID, A_ID_LN))
		return (1);
	else if (!ft_memcmp(id, C_ID, C_ID_LN))
		return (2);
	else if (!ft_memcmp(id, L_ID, L_ID_LN))
		return (3);
	else if (!ft_memcmp(id, SP_ID, SP_ID_LN))
		return (4);
	else if (!ft_memcmp(id, PL_ID, PL_ID_LN))
		return (5);
	else if (!ft_memcmp(id, SQ_ID, SQ_ID_LN))
		return (6);
	else if (!ft_memcmp(id, CY_ID, CY_ID_LN))
		return (7);
	else if (!ft_memcmp(id, TR_ID, TR_ID_LN))
		return (8);
	else if (!ft_memcmp(id, CI_ID, CI_ID_LN))
		return (9);
	return (-1);
}

int	fill_scene(t_scene *scene, char *line)
{
	int		(*f[NB_ID])(t_scene *, char **);
	int		index;
	int		err;
	char	**array;

	if (!line)
		return (EXIT_FAILURE);
	if (!*line || !ft_memcmp(line, SINGLE_LINE_COMMENT, 2))
		return (EXIT_SUCCESS);
	if (ft_strlen(line) < 3)
		return (EXIT_FAILURE);
	array = ft_cs_split(line, SEPARATORS);
	if (!array || !ft_arrlen(array))
	{
		ft_free_strarray(array);
		return (EXIT_FAILURE);
	}
	init_ft_array(f);
	index = id_to_int(*array);
	err = 1;
	if (index > -1)
		err = (f[index](scene, array));
	ft_free_strarray(array);
	return (err);
}

int	cancel_parsing(char *line, int fd)
{
	close(fd);
	if (line)
		free(line);
	return (EXIT_FAILURE);
}

int	parse_file(t_scene *scene, char *file)
{
	int		fd;
	char	*line;
	int		gnl;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	line = NULL;
	gnl = get_next_line(fd, &line);
	while (gnl)
	{
		if (gnl == -1)
			return (cancel_parsing(line, fd));
		else
		{
			if (fill_scene(scene, line))
				return (cancel_parsing(line, fd));
			free(line);
		}
		gnl = get_next_line(fd, &line);
	}
	if (gnl != -1 && fill_scene(scene, line))
		return (cancel_parsing(line, fd));
	free(line);
	close(fd);
	return (EXIT_SUCCESS);
}
