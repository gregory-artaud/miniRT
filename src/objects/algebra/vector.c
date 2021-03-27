/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:38:33 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 15:32:47 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_vect	*init_vect(double x, double y, double z)
{
	t_vect	*v;

	v = (t_vect *)malloc(sizeof(t_vect));
	if (!v)
		return (NULL);
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

t_vect	*v_fmult(double k, t_vect *u)
{
	if (!u)
		return (NULL);
	u->x *= k;
	u->y *= k;
	u->z *= k;
	return (u);
}
