/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:30:50 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 15:31:46 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_vect	*cy_get_x(t_ray *ray, t_cylinder *cy)
{
	t_vect	*x;
	t_vect	*tmp;

	tmp = v_mult(v_dot(ray->dir, cy->ori), cy->ori);
	x = v_minus(ray->dir, tmp);
	free(tmp);
	return (x);
}

t_vect	*cy_get_y(t_ray *ray, t_cylinder *cy)
{
	t_vect	*y;
	t_vect	*delta_p;
	t_vect	*tmp;

	delta_p = v_minus(ray->pos, cy->pos);
	tmp = v_mult(v_dot(delta_p, cy->ori), cy->ori);
	y = v_minus(delta_p, tmp);
	free(tmp);
	free(delta_p);
	return (y);
}
