/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:12:35 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/09 23:21:03 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

int		is_ray_blocked(t_ray *ray, t_list *lst)
{
	t_vect		*tmp;
	t_object	*obj;

	obj = NULL;
	tmp = intersect(ray, lst, &obj);
	if (!tmp)
		return (0);
	free(tmp);
	if (!obj)
		return (0);
	return (1);
}
