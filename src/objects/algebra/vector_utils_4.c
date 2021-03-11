/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:03:29 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/06 17:28:01 by gartaud          ###   ########lyon.fr   */
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

t_vect	*extract_vect(char **s)
{
	t_vect	*u;

	if (!s || ft_memcmp(s[1], ",", 2) ||
		ft_memcmp(s[1], ",", 2) ||
		ft_arrlen(s) < 6)
		return (NULL);
	u = init_vect(0, 0, 0);
	u->x = ft_atof(s[0]);
	u->y = ft_atof(s[2]);
	u->z = ft_atof(s[4]);
	return (u);
}
