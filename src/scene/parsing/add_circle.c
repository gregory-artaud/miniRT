/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 15:54:46 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static int	quit(t_ci *data)
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

static int	check_params(t_scene *scene, char **infos)
{
	int		err;

	if (!scene || !infos)
		return (EXIT_FAILURE);
	err = 0;
	err += (ft_arrlen(infos) != LENGTH_CI_INFOS);
	err += (!ft_is_double((infos[OFFSET_CI_DIAMETER])));
	return (err);
}

static t_ci	*get_data(char **infos)
{
	t_ci	*data;

	data = ft_calloc(1, sizeof(t_ci));
	if (!data)
		return (NULL);
	data->pos = extract_vect(infos + OFFSET_CI_POS);
	data->ori = extract_vect(infos + OFFSET_CI_ORI);
	data->diameter = ft_atof(infos[OFFSET_CI_DIAMETER]);
	data->color = extract_color(infos + OFFSET_CI_COLOR);
	return (data);
}

static int	check_data(t_ci *data)
{
	int		err;

	if (!data)
		return (EXIT_FAILURE);
	err = 0;
	err += (!data->pos);
	err += (!data->ori);
	err += (!is_in_range(data->ori, V_ORI_MIN, V_ORI_MAX));
	err += (!is_in_range(data->color, COLOR_MIN, COLOR_MAX));
	err += (data->diameter < 0);
	err += (!data->color);
	return (err);
}

int	add_circle(t_scene *scene, char **infos)
{
	t_ci		*data;
	t_circle	*obj;

	if (check_params(scene, infos))
		return (EXIT_FAILURE);
	data = get_data(infos);
	if (check_data(data))
		return (quit(data));
	obj = init_ci(data->pos, data->ori, data->diameter, data->color);
	if (!obj)
		return (quit(data));
	push_obj(ft_strdup(CI_ID), obj, scene);
	free(data);
	return (EXIT_SUCCESS);
}
