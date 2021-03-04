/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:12:27 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/04 15:40:34 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "mini_rt.h"

void			init_ft_array(int (*f[NB_ID])(t_scene *, char **))
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

int				id_to_int(char	*id)
{
	if (!ft_memcmp(id, "R", 2))
		return (0);
	else if (!ft_memcmp(id, "A", 2))
		return (1);
	else if (!ft_memcmp(id, "c", 2))
		return (2);
	else if (!ft_memcmp(id, "l", 2))
		return (3);
	else if (!ft_memcmp(id, "sp", 3))
		return (4);
	else if (!ft_memcmp(id, "pl", 3))
		return (5);
	else if (!ft_memcmp(id, "sq", 3))
		return (6);
	else if (!ft_memcmp(id, "cy", 3))
		return (7);
	else if (!ft_memcmp(id, "tr", 3))
		return (8);
	else if (!ft_memcmp(id, "ci", 3))
		return (9);
	return (-1);
}

int				fill_scene(t_scene *scene, char *line)
{
	int		(*f[NB_ID])(t_scene *, char **);
	char	**s_line;
	int		index;

	if (!line)
		return (EXIT_FAILURE);
	if (!*line || !ft_memcmp(line, "//", 2))
		return (EXIT_SUCCESS);
	init_ft_array(f);
	s_line = ft_cs_split(line, SPACES);
	index = id_to_int(s_line[0]);
	if (index > -1)
		return (f[index](scene, s_line));
	ft_free_strarray(s_line);
	return (EXIT_FAILURE);
}

int				parse_file(t_scene *scene, char *file)
{
	int		fd;
	char	*line;
	int		gnl;

	line = NULL;
	gnl = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	while ((gnl = get_next_line(fd, &line)))
		if (gnl == -1)
			return (EXIT_FAILURE);
		else
		{
			if (fill_scene(scene, line))
			{
				free(line);
				return (EXIT_FAILURE);
			}
			free(line);
		}
	if (gnl != -1 && fill_scene(scene, line))
	{
		free(line);
		return (EXIT_FAILURE);
	}
	free(line);
	close(fd);
	return (EXIT_SUCCESS);
}
