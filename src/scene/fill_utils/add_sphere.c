/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/04 16:12:19 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int		add_sphere(t_scene *scene, char **infos)
{
	t_sphere	*sp;
	t_vect		*pos;
	double		diameter;
	t_vect		*color;
	
	if (!scene || !infos)
		return (EXIT_FAILURE);
	if (ft_arrlen(infos) != 4)
	{
		ft_free_strarray(infos);
		return (EXIT_FAILURE);
	}
	pos = extract_vect(infos[1]);
	diameter = ft_atof(infos[2]);
	color = extract_vect(infos[3]);
	put_in_range(color, 0, 255);
	sp = init_sp(pos, diameter, color);
	push_obj("sp", sp, scene);
	ft_free_strarray(infos);
	return (EXIT_SUCCESS);
}
