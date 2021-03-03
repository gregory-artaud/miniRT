/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/03 17:02:10 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int		set_resolution(t_scene *scene, char **infos)
{
	int		length;

	if (!scene || !infos)
		return (EXIT_FAILURE);
	length = ft_arrlen(infos);
	if (length != 3 || scene->r_w != -1 || scene->r_h != -1)
	{
		ft_free_strarray(infos);
		return (EXIT_FAILURE);
	}
	scene->r_w = ft_atoi(infos[1]);
	scene->r_h = ft_atoi(infos[2]);
	ft_free_strarray(infos);
	return (EXIT_SUCCESS);
}
