/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:02:45 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/09 15:31:44 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_object	*init_object(void)
{
	t_object	*obj;

	if (!(obj = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	obj->id = NULL;
	obj->obj = NULL;
	return (obj);
}

void		free_object(void *ptr)
{
	t_object	*obj;

	obj = (t_object *)ptr;
	if (!obj)
		return ;
	if (is_sphere(obj))
		free_sp(obj->obj);
	else if (is_camera(obj))
		free_c(obj->obj);
	else if (is_light(obj))
		free_l(obj->obj);
	free(obj->id);
	free(obj);
	return ;
}
