/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:57:44 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/18 14:42:43 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		trace(t_ray *ray, t_scene *scene)
{
	(void)ray;
	(void)scene;
	return (0);
}

t_ray	*get_ray(t_camera *cam, int x, int y)
{
	t_ray	*ray;

	(void)cam;
	(void)x;
	(void)y;
	if (!(ray = (t_ray *)malloc(sizeof(t_ray))))
		return (NULL);
	return (ray);
}
