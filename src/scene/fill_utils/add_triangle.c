/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/04 16:12:26 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int		add_triangle(t_scene *scene, char **infos)
{
	t_triangle	*tr;
	t_vect		*p1;
	t_vect		*p2;
	t_vect		*p3;
	t_vect		*color;

	if (!scene || !infos)
		return (EXIT_FAILURE);
	if (ft_arrlen(infos) != 5)
	{
		ft_free_strarray(infos);
		return (EXIT_FAILURE);
	}
	p1 = extract_vect(infos[1]);
	p2 = extract_vect(infos[2]);
	p3 = extract_vect(infos[3]);
	color = extract_vect(infos[4]);
	put_in_range(color, 0, 255);
	tr = init_tr(p1, p2, p3, color);
	push_obj("tr", tr, scene);
	ft_free_strarray(infos);
	return (EXIT_SUCCESS);
}
