/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 23:06:49 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/24 11:28:18 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_vect	*calc_diffuse(t_ray *shad_ray, t_light *l, t_vect *normal)
{
	double	dot;
	t_vect	*tmp;
	double	to_light;

	tmp = v_minus(l->pos, shad_ray->pos);
	to_light = v_length(tmp);
	to_light = l->lum / (to_light * to_light);
	free(tmp);
	dot = fmax(0, v_dot(normal, shad_ray->dir));
	return (v_mult(K_D * dot * to_light / 255.0, l->color));
}

t_vect	*calc_specular(t_ray *shad_ray, t_vect *v, t_vect *normal, t_light *l)
{
	double	dot;
	t_vect	*tmp;
	double	to_light;

	tmp = v_minus(l->pos, shad_ray->pos);
	to_light = v_length(tmp);
	to_light = l->lum / (to_light * to_light);
	free(tmp);
	tmp = v_bisect(shad_ray->dir, v);
	dot = fmax(0, v_dot(tmp, normal));
	free(tmp);
	return (v_mult(K_S * to_light * pow(dot, N_S) / 255.0, l->color));
}

t_vect	*calc_ambiant(t_light *l)
{
	if (!l)
		return (NULL);
	return (v_mult(K_A * l->lum / 255.0, l->color));
}

t_vect	*calc_diff_spec(t_ray *ray, t_ray *shad_ray, t_vect *normal, t_light *l)
{
	t_vect	*v;
	t_vect	*diffuse;
	t_vect	*specular;
	t_vect	*res;

	v = v_mult(-1, ray->dir);
	diffuse = calc_diffuse(shad_ray, l, normal);
	specular = calc_specular(shad_ray, v, normal, l);
	res = v_add(diffuse, specular);
	free(diffuse);
	free(specular);
	free(v);
	return (res);
}

t_vect	*parse_lights(t_ray *ray, t_vect *hit, t_vect *normal, t_scene *scene)
{
	t_vect		*l;
	t_vect		*tmp;
	t_list		*node;
	t_object	*current;
	t_ray		*shad_ray;

	l = calc_ambiant(scene->ambiant);
	node = scene->obj;
	shad_ray = NULL;
	while (node && node->content)
	{
		current = (t_object *)node->content;
		tmp = NULL;
		if (is_light(current))
		{
			shad_ray = gen_shadow_ray(hit, ((t_light *)current->obj)->pos);
			if (!is_ray_blocked(shad_ray, scene->obj, (t_light *)current->obj))
				tmp = calc_diff_spec(ray, shad_ray, normal,
									(t_light *)current->obj);
			free_ray(shad_ray);
		}
		v_fadd(l, tmp);
		node = node->next;
	}
	return (l);
}
