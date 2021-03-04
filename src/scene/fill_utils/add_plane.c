/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/04 16:12:14 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int		add_plane(t_scene *scene, char **infos)
{
	t_plane		*pl;
	t_vect		*pos;
	t_vect		*ori;
	t_vect		*color;

	if (!scene || !infos)
		return (EXIT_FAILURE);
	if (ft_arrlen(infos) != 4)
	{
		ft_free_strarray(infos);
		return (EXIT_FAILURE);
	}
	pos = extract_vect(infos[1]);
	ori = extract_vect(infos[2]);
	color = extract_vect(infos[3]);
	put_in_range(color, 0, 255);
	pl = init_pl(pos, ori, color);
	push_obj("pl", pl, scene);
	ft_free_strarray(infos);
	return (EXIT_SUCCESS);
}
