/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/23 16:36:06 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

typedef struct	s_cy
{
	t_ray		*pos_and_ori;
	double		diameter;
	double		height;
	t_vect		*color;
}				t_cy;

static int		quit(t_cy *data)
{
	if (!data)
		return (EXIT_FAILURE);
	if (data->pos_and_ori)
		free_ray(data->pos_and_ori);
	if (data->color)
		free(data->color);
	free(data);
	return (EXIT_FAILURE);
}

static int		check_params(t_scene *scene, char **infos)
{
	int		err;

	if (!scene || !infos || (ft_arrlen(infos) != LENGTH_CY_INFOS))
		return (EXIT_FAILURE);
	err = 0;
	err += (!ft_is_double((infos[OFFSET_CY_DIAMETER])));
	err += (!ft_is_double((infos[OFFSET_CY_HEIGHT])));
	return (err);
}

static t_cy		*get_data(char **infos)
{
	t_cy	*data;
	t_vect	*pos;
	t_vect	*ori;

	data = ft_calloc(1, sizeof(t_cy));
	if (!data)
		return (NULL);
	pos = extract_vect((infos + OFFSET_CY_POS));
	ori = extract_vect((infos + OFFSET_CY_ORI));
	data->pos_and_ori = init_ray(pos, ori);
	data->diameter = ft_atof(infos[OFFSET_CY_DIAMETER]);
	data->height = ft_atof(infos[OFFSET_CY_HEIGHT]);
	data->color = extract_color(infos + OFFSET_CY_COLOR);
	return (data);
}

static int		check_data(t_cy *data)
{
	int		err;

	if (!data || !data->pos_and_ori)
		return (EXIT_FAILURE);
	err = 0;
	err += (!data->pos_and_ori->pos);
	err += (!data->pos_and_ori->dir);
	err += (data->diameter < 0);
	err += (data->height < 0);
	err += (!is_in_range(data->pos_and_ori->dir, V_ORI_MIN, V_ORI_MAX));
	err += (!is_in_range(data->color, COLOR_MIN, COLOR_MAX));
	err += (!data->color);
	return (err);
}

int		add_cylinder(t_scene *scene, char **infos)
{
	t_cy		*data;
	t_cylinder	*cy;

	if (check_params(scene, infos))
		return (EXIT_FAILURE);
	data = get_data(infos);
	if (check_data(data))
		return (quit(data));
	cy = init_cy(data->pos_and_ori, data->diameter, data->height, data->color);
	if (!cy)
		return (quit(data));
	push_obj(ft_strdup(CY_ID), cy, scene);
	//printf("Added cylinder :\n");
	//printf("\tpos: %lf,%lf,%lf\n", cy->pos->x, cy->pos->y, cy->pos->z);
	//printf("\tori: %lf,%lf,%lf\n", cy->ori->x, cy->ori->y, cy->ori->z);
	//printf("\tdiameter: %lf\n", cy->diameter);
	//printf("\theight: %lf\n", cy->height);
	//printf("\tcolor: %lf,%lf,%lf\n", cy->color->x, cy->color->y, cy->color->z);
	free(data);
	return (EXIT_SUCCESS);
}
