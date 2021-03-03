/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:52:58 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/03 17:27:50 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void			print_sp(t_sphere *sp)
{
	printf("\t\t\tsp->pos = %lf, %lf, %lf (%p)\n", sp->pos->x, sp->pos->y, sp->pos->z, sp->pos);
	printf("\t\t\tsp->color = %lf, %lf, %lf (%p)\n", sp->color->x, sp->color->y, sp->color->z, sp->color);
	printf("\t\t\tsp->diameter = %lf\n", sp->diameter);
	return ;
}

void			print_c(t_camera *c)
{
	printf("\t\t\tc->pos = %lf, %lf, %lf\n", c->pos->x, c->pos->y, c->pos->z);
	printf("\t\t\tc->ori = %lf, %lf, %lf\n", c->ori->x, c->ori->y, c->ori->z);
	printf("\t\t\tc->fov = %lf\n", c->fov);
	printf("\t\t\tc->is_used = %d\n", c->is_used);
	return ;
}

void			print_l(t_light *l)
{
	printf("\t\t\tl->pos = %lf, %lf, %lf (%p)\n", l->pos->x, l->pos->y, l->pos->z, l->pos);
	printf("\t\t\tl->color = %lf, %lf, %lf (%p)\n", l->color->x, l->color->y, l->color->z, l->color);
	printf("\t\t\tl->lum = %lf\n", l->lum);
	return ;
}

void			print_obj(void *ptr)
{
	t_object *obj;

	obj = (t_object *)ptr;
	if (!obj)
		return ;
	printf("\t\tobj->id = %s\n", obj->id);
	printf("\t\tobj->obj = %p\n", obj->obj);
	if (is_sphere(obj))
		print_sp(obj->obj);
	else if (is_camera(obj))
		print_c(obj->obj);
	else if (is_light(obj))
		print_l(obj->obj);
	return ;
}

void			print_scene(t_scene *scene)
{
	printf("scene = %p\n", scene);
	printf("\tscene->r_w = %d\n", scene->r_w);
	printf("\tscene->r_h = %d\n", scene->r_h);
	printf("\tscene->obj = %p\n", scene->obj);
	ft_lstiter(scene->obj, print_obj);
}
