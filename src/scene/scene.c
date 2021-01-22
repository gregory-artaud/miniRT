/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:57:25 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/22 22:21:47 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_scene			*init_scene(void)
{
	t_scene		*scene;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	scene->r_w = 0;
	scene->r_h = 0;
	scene->obj = ft_lstnew(NULL);
	return (scene);
}

void			free_scene(t_scene *scene)
{
	ft_lstclear(&(scene->obj), free_object);
	free(scene);
	return ;
}

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
	if (!ft_strncmp(obj->id, "sp", 2))
		print_sp(obj->obj);
	else if (!ft_strncmp(obj->id, "c", 1))
		print_c(obj->obj);
	else if (!ft_strncmp(obj->id, "l", 1))
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

int				fill_scene(t_scene *scene, char *file)
{
	t_object	*obj;
	t_vect		*v1;
	t_vect		*v2;

	(void)file;
	scene->r_w = 960;
	scene->r_h = 540;
	// sphere
	obj = init_object();
	obj->id = ft_strdup("sp");
	v1 = init_vect(30, 10, 12);
	v2 = init_vect(255, 0, 0);
	obj->obj = init_sp(v1, 10, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// camera
	obj = init_object();
	obj->id = ft_strdup("c");
	v1 = init_vect(0, 0, 0);
	v2 = init_vect(0, 0, 0);
	obj->obj = init_c(v1, v2, 90);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// light
	obj = init_object();
	obj->id = ft_strdup("l");
	v1 = init_vect(-1, 0, 0);
	v2 = init_vect(255, 255, 255);
	obj->obj = init_l(v1, 0.7, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	return (EXIT_SUCCESS);
}
