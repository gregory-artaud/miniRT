/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:38:33 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/22 18:40:11 by gartaud          ###   ########lyon.fr   */
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
