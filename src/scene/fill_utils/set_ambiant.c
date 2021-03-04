/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambiant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/04 16:12:31 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "scene.h"

int		set_ambiant(t_scene *scene, char **infos)
{
	double	intensity;
	t_vect	*color;
	t_light	*l;

	if (!scene || !infos)
		return (EXIT_FAILURE);
	if (ft_arrlen(infos) != 3 || scene->ambiant)
	{
		ft_free_strarray(infos);
		return (EXIT_FAILURE);
	}
	intensity = ft_atof(infos[1]);
	color = extract_vect(infos[2]);
	put_in_range(color, 0, 255);
	l = init_l(init_vect(0, 0, 0), intensity, color);
	scene->ambiant = l;
	ft_free_strarray(infos);
	return (EXIT_SUCCESS);
}
