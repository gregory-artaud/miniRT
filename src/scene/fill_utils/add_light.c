/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/04 17:51:54 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int		add_light(t_scene *scene, char **infos)
{
	t_light		*l;
	t_vect		*pos;
	double		intensity;
	t_vect		*color;

	if (!scene || !infos)
		return (EXIT_FAILURE);
	if (ft_arrlen(infos) != 4)
	{
		ft_free_strarray(infos);
		return (EXIT_FAILURE);
	}
	pos = extract_vect(infos[1]);
	intensity = ft_atof(infos[2]);
	if (intensity < 0.0 || intensity > 1.0)
		intensity = floor(fmax(fmin(intensity, 1), 0));
	color = extract_vect(infos[3]);
	put_in_range(color, 0, 255);
	l = init_l(pos, intensity, color);
	push_obj("l", l, scene);
	ft_free_strarray(infos);
	return (EXIT_SUCCESS);
}
