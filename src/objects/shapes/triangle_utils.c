/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 01:52:02 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/25 18:22:00 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_plane	*find_plane(t_vect *p1, t_vect *p2, t_vect *p3, t_vect *color)
{
	t_vect	*tmp1;
	t_vect	*tmp2;
	t_vect	*normal;
	t_plane	*pl;

	tmp1 = v_minus(p1, p2);
	tmp2 = v_minus(p1, p3);
	normal = v_prod(tmp1, tmp2);
	normalize(normal);
	free(tmp1);
	free(tmp2);
	pl = init_pl(dup_vect(p1), init_vect(0, 0, 0), color);
	free(pl->normal);
	pl->normal = normal;
	return (pl);
}

int		is_outside(t_vect *p1, t_vect *p2, t_vect *p3, t_vect *hit)
{
	t_vect	*v1;
	t_vect	*v2;
	t_vect	*v3;
	int		res;

	res = 0;
	v1 = v_minus(p2, p1);
	v2 = v_minus(p3, p1);
	v3 = v_minus(hit, p1);
	p1 = v_prod(v1, v2);
	p2 = v_prod(v1, v3);
	if (v_dot(p1, p2) < 0)
		res = 1;
	free(v1);
	free(v2);
	free(v3);
	free(p1);
	free(p2);
	return (res);
}
