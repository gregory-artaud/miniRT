/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:15:11 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/15 18:26:57 by gartaud          ###   ########lyon.fr   */
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

int		is_ray_blocked(t_ray *ray, t_list *lst, t_light *l)
{
	double		to_light;
	double		t;
	t_vect		*tmp;
	t_object	*obj;

	tmp = v_minus(ray->pos, l->pos);
	to_light = v_length(tmp);
	free(tmp);
	obj = NULL;
	t = intersect(ray, lst, &obj);
	if (!obj)
		return (0);
	return (t < to_light);
}
