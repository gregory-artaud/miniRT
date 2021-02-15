/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:12:35 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/15 15:29:03 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

int		is_ray_blocked(t_ray *ray, t_list *lst, t_light *l)
{
	double		t;
	double		to_light;
	t_vect		*tmp;
	t_object	*obj;

	obj = NULL;
	t = intersect(ray, lst, &obj);
	tmp = v_minus(ray->pos, l->pos);
	to_light = v_length(tmp);
	free(tmp);
	if (!obj)
		return (0);
	return (t < to_light);
}
