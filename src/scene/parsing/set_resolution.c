/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/22 17:44:40 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int		set_resolution(t_scene *scene, char **infos)
{
	if (!scene || !infos ||
		(ft_arrlen(infos) != LENGTH_R_INFOS) ||
		(scene->r_h != -1) || (scene->r_w != -1))
		return (EXIT_FAILURE);
	if (!ft_is_int(infos[OFFSET_R_W]) || !ft_is_int(infos[OFFSET_R_H]))
		return (EXIT_FAILURE);
	scene->r_w = ft_atoi(infos[OFFSET_R_W]);
	scene->r_h = ft_atoi(infos[OFFSET_R_H]);
	return (EXIT_SUCCESS);
}
