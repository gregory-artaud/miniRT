/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:15:11 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/23 20:23:04 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_ray	*init_ray(t_vect *pos, t_vect *dir)
{
	t_ray	*ray;

	if (!(ray = (t_ray *)malloc(sizeof(t_ray))))
		return (NULL);
	ray->pos = pos;
	ray->dir = dir;
	return (ray);
}

void	free_ray(t_ray *ray)
{
	if (!ray)
		return ;
	free(ray->pos);
	free(ray->dir);
	free(ray);
	return ;
}
