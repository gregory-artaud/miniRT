/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_utils_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:36:08 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/15 16:47:35 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_vect	*v_vmult(t_vect *u, t_vect *v)
{
	t_vect	*w;

	if (!u || !v)
		return (NULL);
	w = dup_vect(u);
	w->x *= v->x;
	w->y *= v->y;
	w->z *= v->z;
	return (w);
}

void	translate(t_vect *u, double k, t_vect *v)
{
	u->x += k * v->x;
	u->y += k * v->y;
	u->z += k * v->z;
	return ;
}

void	v_cos(t_vect *u)
{
	u->x = cos(u->x);
	u->y = cos(u->y);
	u->z = cos(u->z);
	return ;
}

void	v_sin(t_vect *u)
{
	u->x = sin(u->x);
	u->y = sin(u->y);
	u->z = sin(u->z);
	return ;
}
