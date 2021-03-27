/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 15:53:31 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "scene.h"

static int	quit(t_cam *data)
{
	if (!data)
		return (EXIT_FAILURE);
	if (data->pos)
		free(data->pos);
	if (data->ori)
		free(data->ori);
	free(data);
	return (EXIT_FAILURE);
}

static int	check_params(t_scene *scene, char **infos)
{
	int		err;

	if (!scene || !infos || (ft_arrlen(infos) != LENGTH_C_INFOS))
		return (EXIT_FAILURE);
	err = 0;
	err += (!ft_is_double(infos[OFFSET_C_FOV]));
	return (err);
}

static t_cam	*get_data(char **infos)
{
	t_cam	*data;

	data = ft_calloc(1, sizeof(t_cam));
	if (!data)
		return (NULL);
	data->pos = extract_vect(infos + OFFSET_C_POS);
	data->ori = extract_vect(infos + OFFSET_C_ORI);
	data->fov = ft_atof(infos[OFFSET_C_FOV]);
	return (data);
}

static int	check_data(t_cam *data)
{
	int		err;

	if (!data)
		return (EXIT_FAILURE);
	err = 0;
	err += (!data->pos);
	err += (!data->ori);
	err += (data->fov < C_FOV_MIN || data->fov > C_FOV_MAX);
	err += (!is_in_range(data->ori, V_ORI_MIN, V_ORI_MAX));
	return (err);
}

int	add_camera(t_scene *scene, char **infos)
{
	t_cam		*data;
	t_camera	*c;

	if (check_params(scene, infos))
		return (EXIT_FAILURE);
	data = get_data(infos);
	if (check_data(data))
		return (quit(data));
	c = init_c(data->pos, data->ori, data->fov);
	if (!c)
		return (quit(data));
	push_obj(ft_strdup("c"), c, scene);
	if (!scene->current_cam)
	{
		c->is_used = 1;
		scene->current_cam = c;
	}
	free(data);
	return (EXIT_SUCCESS);
}
