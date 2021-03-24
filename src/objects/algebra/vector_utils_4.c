/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:03:29 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/24 08:42:03 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

int		is_in_range(t_vect *u, double a, double b)
{
	if (!u)
		return (0);
	return (u->x >= a &&  u->x <= b &&
			u->y >= a &&  u->y <= b &&
			u->z >= a &&  u->z <= b);
}

void	put_in_range(t_vect *u, double min, double max)
{
	u->x = floor(fmax(fmin(u->x, max), min));
	u->y = floor(fmax(fmin(u->y, max), min));
	u->z = floor(fmax(fmin(u->z, max), min));
	return ;
}

void	v_add_v(t_vect *u, t_vect *v)
{
	u->x += v->x;
	u->y += v->y;
	u->z += v->z;
}
