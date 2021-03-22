/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/22 17:04:57 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

typedef struct	s_pl
{
	t_vect		*pos;
	t_vect		*ori;
	t_vect		*color;
}				t_pl;

static int		quit(t_pl *data)
{
	if (!data)
		return (EXIT_FAILURE);
	if (data->pos)
		free(data->pos);
	if (data->ori)
		free(data->ori);
	if (data->color)
		free(data->color);
	free(data);
	return (EXIT_FAILURE);
}

static int		check_params(t_scene *scene, char **infos)
{
	int		err;

	if (!scene || !infos)
		return (EXIT_FAILURE);
	err = 0;
	err += (ft_arrlen(infos) != LENGTH_PL_INFOS);
	return (err);
}

static t_pl		*get_data(char **infos)
{
	t_pl	*data;

	data = ft_calloc(1, sizeof(t_pl));
	if (!data)
		return (NULL);
	data->pos = extract_vect(infos + OFFSET_PL_POS);
	data->ori = extract_vect(infos + OFFSET_PL_ORI);
	data->color = extract_color(infos + OFFSET_PL_COLOR);
	return (data);
}

static int		check_data(t_pl *data)
{
	int		err;

	if (!data)
		return (EXIT_FAILURE);
	err = 0;
	err += (!data->pos);
	err += (!data->ori);
	err += (!is_in_range(data->ori, V_ORI_MIN, V_ORI_MAX));
	err += (!is_in_range(data->color, COLOR_MIN, COLOR_MAX));
	err += (!data->color);
	return (err);
}

int		add_plane(t_scene *scene, char **infos)
{
	t_pl		*data;
	t_plane		*pl;

	if (check_params(scene, infos))
		return (EXIT_FAILURE);
	data = get_data(infos);
	if (check_data(data))
		return (quit(data));
	pl = init_pl(data->pos, data->ori, data->color);
	if (!pl)
		return (quit(data));
	push_obj(ft_strdup(PL_ID), pl, scene);
	free(data);
	return (EXIT_SUCCESS);
}
