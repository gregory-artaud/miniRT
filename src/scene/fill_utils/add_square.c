/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/04 16:12:22 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int		add_square(t_scene *scene, char **infos)
{
	t_square	*sq;
	t_vect		*pos;
	t_vect		*ori;
	t_vect		*color;
	double		size;

	if (!scene || !infos)
		return (EXIT_FAILURE);
	if (ft_arrlen(infos) != 5)
	{
		ft_free_strarray(infos);
		return (EXIT_FAILURE);
	}
	pos = extract_vect(infos[1]);
	ori = extract_vect(infos[2]);
	size = ft_atof(infos[3]);
	color = extract_vect(infos[4]);
	put_in_range(color, 0, 255);
	sq = init_sq(pos, ori, size, color);
	push_obj("sq", sq, scene);
	ft_free_strarray(infos);
	return (EXIT_SUCCESS);
}
