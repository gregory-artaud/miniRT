/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:40:38 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/22 21:45:11 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_sphere		*init_sp(t_vect *pos, double diameter, t_vect *color)
{
	t_sphere	*sp;

	if (!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sp->pos = pos;
	sp->diameter = diameter;
	sp->color = color;
	return (sp);
}

void			free_sp(t_sphere *sp)
{
	free(sp->pos);
	free(sp->color);
	free(sp);
	return ;
}
