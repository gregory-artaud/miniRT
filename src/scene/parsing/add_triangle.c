/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 14:06:30 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

typedef struct	s_tr
{
	t_vect		*p1;
	t_vect		*p2;
	t_vect		*p3;
	t_vect		*color;
}				t_tr;

static int		quit(t_tr *data)
{
	if (!data)
		return (EXIT_FAILURE);
	if (data->p1)
		free(data->p1);
	if (data->p2)
		free(data->p2);
	if (data->p3)
		free(data->p3);
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
	err += (ft_arrlen(infos) != LENGTH_TR_INFOS);
	return (err);
}

static t_tr		*get_data(char **infos)
{
	t_tr	*data;

	data = ft_calloc(1, sizeof(t_tr));
	if (!data)
		return (NULL);
	data->p1 = extract_vect(infos + OFFSET_TR_P1);
	data->p2 = extract_vect(infos + OFFSET_TR_P2);
	data->p3 = extract_vect(infos + OFFSET_TR_P3);
	data->color = extract_color(infos + OFFSET_TR_COLOR);
	return (data);
}

static int		check_data(t_tr *data)
{
	int		err;

	if (!data)
		return (EXIT_FAILURE);
	err = 0;
	err += (!data->p1);
	err += (!data->p2);
	err += (!data->p3);
	err += (!is_in_range(data->color, COLOR_MIN, COLOR_MAX));
	err += (!data->color);
	return (err);
}

int				add_triangle(t_scene *scene, char **infos)
{
	t_tr		*data;
	t_triangle	*tr;

	if (check_params(scene, infos))
		return (EXIT_FAILURE);
	data = get_data(infos);
	if (check_data(data))
		return (quit(data));
	tr = init_tr(data->p1, data->p2, data->p3, data->color);
	if (!tr)
		return (quit(data));
	push_obj(ft_strdup(TR_ID), tr, scene);
	free(data);
	return (EXIT_SUCCESS);
}
