/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:03:17 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 15:33:02 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_vect	*v_minus(t_vect *u, t_vect *v)
{
	t_vect	*w;

	if (!u || !v)
		return (NULL);
	w = init_vect(u->x - v->x, u->y - v->y, u->z - v->z);
	return (w);
}

double	v_length(t_vect *u)
{
	if (!u)
		return (0);
	return (sqrt((u->x * u->x) + (u->y * u->y) + (u->z * u->z)));
}

void	normalize(t_vect *u)
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

double	v_dot(t_vect *u, t_vect *v)
{
	if (!u || !v)
		return (-1);
	return (u->x * v->x + u->y * v->y + u->z * v->z);
}

t_vect	*v_mult(double k, t_vect *u)
{
	return (init_vect(k * u->x, k * u->y, k * u->z));
}
