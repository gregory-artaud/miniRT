/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambiant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:10:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/16 16:35:10 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "scene.h"

int				failure(t_vect *color, t_light *l)
{
	if (l)
	{
		free_l(l);
		color = NULL;
	}
	if (color)
		free(color);
	return (EXIT_FAILURE);
}

int				set_ambiant(t_scene *scene, char **infos)
{
	double	lum;
	t_vect	*color;
	t_light	*l;

	if (!scene || !infos ||
		(ft_arrlen(infos) != LENGTH_A_INFOS) ||
		scene->ambiant)
		return (EXIT_FAILURE);
	if (!ft_is_double(infos[OFFSET_A_INTENSITY]))
		return (EXIT_FAILURE);
	lum = ft_atof(infos[OFFSET_A_INTENSITY]);
	if (lum < 0 || lum > 1)
		return (EXIT_FAILURE);
	color = extract_color(infos + OFFSET_A_COLOR);
	if (!color)
		return (failure(color, NULL));
	l = init_l(init_vect(0, 0, 0), lum, color);
	scene->ambiant = l;
	return (EXIT_SUCCESS);
}
