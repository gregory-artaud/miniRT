/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:46:26 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 15:34:20 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_vect	*v_add(t_vect *u, t_vect *v)
{
	return (init_vect(u->x + v->x,
			u->y + v->y,
			u->z + v->z));
}

void	v_fadd(t_vect *u, t_vect *v)
{
	if (!v)
		return ;
	if (u)
	{
		u->x += v->x;
		u->y += v->y;
		u->z += v->z;
	}
	free(v);
	return ;
}

t_vect	*dup_vect(t_vect *u)
{
	t_vect	*v;

	if (!u)
		return (NULL);
	v = init_vect(u->x, u->y, u->z);
	return (v);
}

t_vect	*v_bisect(t_vect *u, t_vect *v)
{
	t_vect	*res;

	res = v_add(u, v);
	normalize(res);
	return (res);
}

double	v_cmp(t_vect *u, t_vect *v)
{
	double	u_ln;
	double	v_ln;

	u_ln = v_length(u);
	v_ln = v_length(v);
	return (u_ln - v_ln);
}
