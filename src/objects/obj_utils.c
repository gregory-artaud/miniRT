/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:10:29 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/02 18:11:35 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_vect	*obj_get_color(t_object *obj)
{
	if (!obj)
		return (NULL);
	if (!ft_memcmp(obj->id, "sp", 3))
		return (((t_sphere *)obj->obj)->color);
	return (NULL);
}

int		c_to_hex(t_vect *c)
{
	int		hex;
	
	if (!c)
		return (0);
	if (c->x < 0 || c->x > 255 ||
		c->y < 0 || c->y > 255 ||
		c->z < 0 || c->z > 255)
		return (0x0);
	hex = c->x;
	hex *= 16 * 16;
	hex += c->y;
	hex *= 16 * 16;
	hex += c->z;
	return (hex);
}
