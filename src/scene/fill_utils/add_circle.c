/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/04 16:11:46 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int		add_circle(t_scene *scene, char **infos)
{
	t_circle	*ci;
	t_vect		*pos;
	t_vect		*ori;
	double		diameter;
	t_vect		*color;

	if (!scene || !infos)
		return (EXIT_FAILURE);
	if (ft_arrlen(infos) != 5)
	{
		ft_free_strarray(infos);
		return (EXIT_FAILURE);
	}
	pos = extract_vect(infos[1]);
	ori = extract_vect(infos[2]);
	diameter = ft_atof(infos[3]);
	color = extract_vect(infos[4]);
	put_in_range(color, 0, 255);
	ci = init_ci(pos, ori, diameter, color);
	push_obj("ci", ci, scene);
	ft_free_strarray(infos);
	return (EXIT_SUCCESS);
}
