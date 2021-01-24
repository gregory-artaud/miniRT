/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:38:33 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/23 23:25:43 by gartaud          ###   ########lyon.fr   */
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

t_vect			*minus_vect(t_vect *u, t_vect *v)
{
	t_vect	*w;

	if (!u || !v)
		return (NULL);
	w = init_vect(u->x - v->x, u->y - v->y, u->z - v->z);
	free(u);
	return (w);
}

void			normalize(t_vect *u)
{
	double	norme;

	if (!u)
		return ;
	norme = sqrt((u->x * u->x) + (u->y * u->y) + (u->z * u->z));
	u->x /= norme;
	u->y /= norme;
	u->z /= norme;
	return ;
}
