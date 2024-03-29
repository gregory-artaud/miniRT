/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 22:04:15 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 15:16:12 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_light	*init_l(t_vect *pos, double lum, t_vect *color)
{
	t_light		*l;

	l = (t_light *)malloc(sizeof(t_light));
	if (!l)
		return (NULL);
	l->pos = pos;
	l->lum = lum;
	l->color = color;
	return (l);
}

void	free_l(t_light *l)
{
	free(l->pos);
	free(l->color);
	free(l);
	return ;
}

int	is_light(t_object *obj)
{
	return (!ft_memcmp(obj->id, "l", 2));
}
