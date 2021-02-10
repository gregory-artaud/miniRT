/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_utils_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:36:08 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/10 01:30:30 by gartaud          ###   ########lyon.fr   */
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

void	apply_matrix(t_vect *u, double m[3][3])
{
	u->x = m[0][0] * u->x + m[0][1] * u->y + m[0][2] * u->z;
	u->y = m[1][0] * u->x + m[1][1] * u->y + m[1][2] * u->z;
	u->z = m[2][0] * u->x + m[2][1] * u->y + m[2][2] * u->z;
	return ;
}
