/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/03 16:49:51 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int		add_cylinder(t_scene *scene, char **infos)
{
	t_cylinder		*cy;
	t_ray			*pos_and_ori;
	double			diameter;
	double			height;
	t_vect			*color;

	if (!scene || !infos)
		return (EXIT_FAILURE);
	if (ft_arrlen(infos) != 6)
	{
		ft_free_strarray(infos);
		return (EXIT_FAILURE);
	}
	pos_and_ori = init_ray(extract_vect(infos[1]), extract_vect(infos[2]));
	diameter = ft_atof(infos[3]);
	height = ft_atof(infos[4]);
	color = extract_vect(infos[5]);
	cy = init_cy(pos_and_ori, diameter, height, color);
	push_obj("cy", cy, scene);
	ft_free_strarray(infos);
	return (EXIT_SUCCESS);
}
