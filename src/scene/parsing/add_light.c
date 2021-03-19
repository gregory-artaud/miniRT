/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/19 21:09:59 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

typedef struct	s_l
{
	t_vect		*pos;
	double		lum;
	t_vect		*color;
}				t_l;

static int		quit(t_l *data)
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

static int		check_params(t_scene *scene, char **infos)
{
	int		err;

	if (!scene || !infos)
		return (EXIT_FAILURE);
	err = 0;
	err += (ft_arrlen(infos) != LENGTH_L_INFOS);
	err += (!ft_is_double((infos[OFFSET_L_INTENSITY])));
	return (err);
}

static t_l		*get_data(char **infos)
{
	t_l	*data;

	data = ft_calloc(1, sizeof(t_l));
	if (!data)
		return (NULL);
	data->pos = extract_vect(infos + OFFSET_L_POS);
	data->lum = ft_atof(infos[OFFSET_L_INTENSITY]);
	data->color = extract_color(infos + OFFSET_L_COLOR);
	return (data);
}

static int		check_data(t_l *data)
{
	int		err;

	if (!data)
		return (EXIT_FAILURE);
	err = 0;
	err += (!data->pos);
	err += (data->lum < 0 || data->lum > 1);
	err += (!data->color);
	return (err);
}

int		add_light(t_scene *scene, char **infos)
{
	t_l		*data;
	t_light	*l;

	if (check_params(scene, infos))
		return (EXIT_FAILURE);
	data = get_data(infos);
	if (check_data(data))
		return (quit(data));
	l = init_l(data->pos, data->lum, data->color);
	if (!l)
		return (quit(data));
	push_obj(ft_strdup(L_ID), l, scene);
	free(data);
	return (EXIT_SUCCESS);
}
