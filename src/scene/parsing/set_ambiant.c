/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambiant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/22 17:58:59 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "scene.h"

typedef struct		s_ambiant
{
	double			lum;
	t_vect			*color;
}					t_ambiant;

static int			quit(t_ambiant *data)
{
	if (!data)
		return (EXIT_FAILURE);
	if (data->color)
		free(data->color);
	free(data);
	return (EXIT_FAILURE);
}

static int			check_params(t_scene *scene, char **infos)
{
	int		err;

	if (!scene || !infos || (ft_arrlen(infos) != LENGTH_A_INFOS))
		return (EXIT_FAILURE);
	err = 0;
	err += (!ft_is_double(infos[OFFSET_A_INTENSITY]));
	err += (!!scene->ambiant);
	return (err);
}

static t_ambiant	*get_data(char **infos)
{
	t_ambiant	*data;

	data = ft_calloc(1, sizeof(t_ambiant));
	if (!data)
		return (NULL);
	data->lum = ft_atof(infos[OFFSET_A_INTENSITY]);
	data->color = extract_color(infos + OFFSET_A_COLOR);
	return (data);
}

static int		check_data(t_ambiant *data)
{
	int		err;

	if (!data)
		return (EXIT_FAILURE);
	err = 0;
	err += (!data->color);
	err += (!is_in_range(data->color, COLOR_MIN, COLOR_MAX));
	err += (data->lum < 0 || data->lum > 1);
	return (err);
}

int				set_ambiant(t_scene *scene, char **infos)
{
	t_ambiant	*data;
	t_light		*ambiant;

	if (check_params(scene, infos))
		return (EXIT_FAILURE);
	data = get_data(infos);
	if (check_data(data))
		return (quit(data));
	ambiant = init_l(init_vect(0,0,0), data->lum, data->color);
	if (!ambiant)
		return (quit(data));
	scene->ambiant = ambiant;
	free(data);
	return (EXIT_SUCCESS);
}
