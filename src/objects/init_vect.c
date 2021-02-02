/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:38:33 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/02 18:33:09 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_vect			*init_vect(double x, double y, double z)
{
	t_vect	*v;

	if (!(v = (t_vect *)malloc(sizeof(t_vect))))
		return (NULL);
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

t_vect			*dup_vect(t_vect *u)
{
	t_vect	*v;

	if (!u)
		return (NULL);
	v = init_vect(u->x, u->y, u->z);
	return (v);
}

t_vect			*v_minus(t_vect *u, t_vect *v)
{
	t_vect	*w;

	if (!u || !v)
		return (NULL);
	w = init_vect(u->x - v->x, u->y - v->y, u->z - v->z);
	return (w);
}

double			v_length(t_vect *u)
{
	if (!u)
		return (0);
	return (sqrt((u->x * u->x) + (u->y * u->y) + (u->z * u->z)));
}

void			normalize(t_vect *u)
{
	double	norme;

	if (!u)
		return ;
	norme = v_length(u);
	u->x /= norme;
	u->y /= norme;
	u->z /= norme;
	return ;
}

double			v_dot(t_vect *u, t_vect *v)
{
	if (!u || !v)
		return (0);
	return (u->x * v->x + u->y * v->y + u->z * v->z);
}

t_vect			*v_mult(double k, t_vect *u)
{
	return (init_vect(k * u->x, k * u->y, k * u->z));
}
