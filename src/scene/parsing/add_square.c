/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/22 13:19:36 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

typedef struct	s_sq
{
	t_vect		*pos;
	t_vect		*ori;
	double		size;
	t_vect		*color;
}				t_sq;

static int		quit(t_sq *data)
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
	err += (ft_arrlen(infos) != LENGTH_SQ_INFOS);
	err += (!ft_is_double((infos[OFFSET_SQ_SIZE])));
	return (err);
}

static t_sq		*get_data(char **infos)
{
	t_sq	*data;

	data = ft_calloc(1, sizeof(t_sq));
	if (!data)
		return (NULL);
	data->pos = extract_vect(infos + OFFSET_SQ_POS);
	data->ori = extract_vect(infos + OFFSET_SQ_ORI);
	data->size = ft_atof(infos[OFFSET_SQ_SIZE]);
	data->color = extract_color(infos + OFFSET_SQ_COLOR);
	return (data);
}

static int		check_data(t_sq *data)
{
	int		err;

	if (!data)
		return (EXIT_FAILURE);
	err = 0;
	err += (!data->pos);
	err += (!data->ori);
	err += (!is_in_range(data->ori, V_ORI_MIN, V_ORI_MAX));
	err += (data->size < 0);
	err += (!data->color);
	return (err);
}

int		add_square(t_scene *scene, char **infos)
{
	t_sq		*data;
	t_square	*obj;

	if (check_params(scene, infos))
		return (EXIT_FAILURE);
	data = get_data(infos);
	if (check_data(data))
		return (quit(data));
	obj = init_sq(data->pos, data->ori, data->size, data->color);
	if (!obj)
		return (quit(data));
	push_obj(ft_strdup(SQ_ID), obj, scene);
	free(data);
	return (EXIT_SUCCESS);
}
