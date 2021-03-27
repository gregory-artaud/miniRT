/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 15:55:40 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static int	quit(t_sp *data)
{
	if (!data)
		return (EXIT_FAILURE);
	if (data->pos)
		free(data->pos);
	if (data->color)
		free(data->color);
	free(data);
	return (EXIT_FAILURE);
}

static int	check_params(t_scene *scene, char **infos)
{
	int		err;

	if (!scene || !infos || (ft_arrlen(infos) != LENGTH_SP_INFOS))
		return (EXIT_FAILURE);
	err = 0;
	err += (!ft_is_double((infos[OFFSET_SP_DIAMETER])));
	return (err);
}

static t_sp	*get_data(char **infos)
{
	t_sp	*data;

	data = ft_calloc(1, sizeof(t_sp));
	if (!data)
		return (NULL);
	data->pos = extract_vect(infos + OFFSET_SP_POS);
	data->diameter = ft_atof(infos[OFFSET_SP_DIAMETER]);
	data->color = extract_color(infos + OFFSET_SP_COLOR);
	return (data);
}

static int	check_data(t_sp *data)
{
	int		err;

	if (!data)
		return (EXIT_FAILURE);
	err = 0;
	err += (!data->pos);
	err += (data->diameter < 0);
	err += (!is_in_range(data->color, COLOR_MIN, COLOR_MAX));
	err += (!data->color);
	return (err);
}

int	add_sphere(t_scene *scene, char **infos)
{
	t_sp		*data;
	t_sphere	*obj;

	if (check_params(scene, infos))
		return (EXIT_FAILURE);
	data = get_data(infos);
	if (check_data(data))
		return (quit(data));
	obj = init_sp(data->pos, data->diameter, data->color);
	if (!obj)
		return (quit(data));
	push_obj(ft_strdup(SP_ID), obj, scene);
	free(data);
	return (EXIT_SUCCESS);
}
