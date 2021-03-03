/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/03 16:56:57 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int		add_camera(t_scene *scene, char **infos)
{
	t_camera	*c;
	t_vect		*pos;
	t_vect		*ori;
	double		fov;

	if (!scene || !infos)
		return (EXIT_FAILURE);
	if (ft_arrlen(infos) != 4)
	{
		ft_free_strarray(infos);
		return (EXIT_FAILURE);
	}
	pos = extract_vect(infos[1]);
	ori = extract_vect(infos[2]);
	fov = ft_atof(infos[3]);
	c = init_c(pos, ori, fov);
	push_obj("c", c, scene);
	if (!scene->current_cam)
	{
		c->is_used = 1;
		scene->current_cam = c;
	}
	ft_free_strarray(infos);
	return (EXIT_SUCCESS);
}
