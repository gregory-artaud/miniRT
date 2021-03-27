/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:15:31 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 15:37:16 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

void	calc_rot(double m[3][3], t_vect *angles)
{
	t_vect	*c;
	t_vect	*s;

	c = v_mult(M_PI, angles);
	s = dup_vect(c);
	v_cos(c);
	v_sin(s);
	m[0][0] = c->y * c->z;
	m[0][1] = -s->z * c->x + c->z * s->y * s->x;
	m[0][2] = s->z * s->x + c->z * s->y * c->x;
	m[1][0] = s->z * c->y;
	m[1][1] = c->z * c->x + s->z * s->y * s->x;
	m[1][2] = -c->z * s->x + s->z * s->y * c->x;
	m[2][0] = -s->y;
	m[2][1] = c->y * s->x;
	m[2][2] = c->y * c->x;
	free(c);
	free(s);
	return ;
}

void	apply_matrix(t_vect *u, double m[3][3])
{
	t_vect	*tmp;

	tmp = dup_vect(u);
	u->x = m[0][0] * tmp->x + m[0][1] * tmp->y + m[0][2] * tmp->z;
	u->y = m[1][0] * tmp->x + m[1][1] * tmp->y + m[1][2] * tmp->z;
	u->z = m[2][0] * tmp->x + m[2][1] * tmp->y + m[2][2] * tmp->z;
	free(tmp);
	return ;
}
