/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:12:27 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/18 09:03:29 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "mini_rt.h"

int				fill_scene(t_scene *scene, char *file)
{
	t_object	*obj;
	t_light		*l;
	t_vect		*v1;
	t_vect		*v2;
	t_vect		*v3;

	(void)file;
	scene->r_w = 500;
	scene->r_h = 300;
	// sphere 1
	obj = init_object();
	obj->id = ft_strdup("sp");
	v1 = init_vect(1, 0, -2);
	v2 = init_vect(255, 0, 0);
	obj->obj = init_sp(v1, 1, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// sphere 2
	obj = init_object();
	obj->id = ft_strdup("sp");
	v1 = init_vect(0, 1, -2);
	v2 = init_vect(0, 0, 255);
	obj->obj = init_sp(v1, 0.7, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// sphere 3
	obj = init_object();
	obj->id = ft_strdup("sp");
	v1 = init_vect(-1, 0, -2);
	v2 = init_vect(177, 133, 255);
	obj->obj = init_sp(v1, 0.6, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// sphere 4
	obj = init_object();
	obj->id = ft_strdup("sp");
	v1 = init_vect(0, 0, -1.5);
	v2 = init_vect(0, 255, 0);
	obj->obj = init_sp(v1, 0.1, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// sphere 5
	obj = init_object();
	obj->id = ft_strdup("sp");
	v1 = init_vect(0, 0, 2);
	v2 = init_vect(255, 0, 0);
	obj->obj = init_sp(v1, 1, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// plan 1
	obj = init_object();
	obj->id = ft_strdup("pl");
	v1 = init_vect(0, -0.9, 0);
	v2 = init_vect(0, 0, 0);
	v3 = init_vect(0, 255, 0);
	obj->obj = init_pl(v1, v2, v3);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// plan 2
	obj = init_object();
	obj->id = ft_strdup("pl");
	v1 = init_vect(0, 0, -5);
	v2 = init_vect(0.5, 0, 0);
	v3 = init_vect(0, 255, 128);
	obj->obj = init_pl(v1, v2, v3);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// plan 3
	obj = init_object();
	obj->id = ft_strdup("pl");
	v1 = init_vect(-5, 0, 0);
	v2 = init_vect(0, 0, 0.5);
	v3 = init_vect(0, 255, 128);
	obj->obj = init_pl(v1, v2, v3);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// camera 1
	obj = init_object();
	obj->id = ft_strdup("c");
	v1 = init_vect(1, 1, 0);
	v2 = init_vect(-0.15, 0.2, 0);
	obj->obj = init_c(v1, v2, 90);
	((t_camera *)obj->obj)->is_used = 0;
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// camera 2
	obj = init_object();
	obj->id = ft_strdup("c");
	v1 = init_vect(0, 0.2, 0);
	v2 = init_vect(0, 0, 0);
	obj->obj = init_c(v1, v2, 90);
	((t_camera *)obj->obj)->is_used = 1;
	scene->current_cam = obj->obj;
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// camera 3
	obj = init_object();
	obj->id = ft_strdup("c");
	v1 = init_vect(-1, 1, 0);
	v2 = init_vect(-0.15, -0.2, 0);
	obj->obj = init_c(v1, v2, 90);
	((t_camera *)obj->obj)->is_used = 0;
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// light 1
	obj = init_object();
	obj->id = ft_strdup("l");
	v1 = init_vect(0, 4, -1);
	v2 = init_vect(255, 255, 255);
	obj->obj = init_l(v1, 0.9, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// light 2
	obj = init_object();
	obj->id = ft_strdup("l");
	v1 = init_vect(-1.5, 1.5, -1);
	v2 = init_vect(255, 255, 255);
	obj->obj = init_l(v1, 0.8, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// light 3
	obj = init_object();
	obj->id = ft_strdup("l");
	v1 = init_vect(2, 1, -1);
	v2 = init_vect(255, 255, 255);
	obj->obj = init_l(v1, 0.7, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// ambiant light
	v1 = init_vect(0, 0, 0);
	v2 = init_vect(255, 255, 255);
	l = init_l(v1, 0.4, v2);
	scene->ambiant = l;
	return (EXIT_SUCCESS);
}

/*
int				fill_scene(t_scene *scene, char *file)
{
	t_object	*obj;
	t_light		*l;
	t_vect		*v1;
	t_vect		*v2;
	t_vect		*v3;

	(void)file;
	scene->r_w = 500;
	scene->r_h = 300;
	// sphere 1
	obj = init_object();
	obj->id = ft_strdup("sp");
	v1 = init_vect(1, 0, -2);
	v2 = init_vect(255, 255, 255);
	obj->obj = init_sp(v1, 1, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// sphere 2
	obj = init_object();
	obj->id = ft_strdup("sp");
	v1 = init_vect(0, 0.5, -2);
	v2 = init_vect(255, 255, 255);
	obj->obj = init_sp(v1, 0.7, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// sphere 3
	obj = init_object();
	obj->id = ft_strdup("sp");
	v1 = init_vect(-1, 0, -2);
	v2 = init_vect(255, 255, 255);
	obj->obj = init_sp(v1, 0.6, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// sphere 4
	obj = init_object();
	obj->id = ft_strdup("sp");
	v1 = init_vect(0, 0, -1.5);
	v2 = init_vect(255, 255, 255);
	obj->obj = init_sp(v1, 0.1, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// sphere 5
	obj = init_object();
	obj->id = ft_strdup("sp");
	v1 = init_vect(0, 0, 2);
	v2 = init_vect(255, 255, 255);
	obj->obj = init_sp(v1, 1, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// plan 1
	obj = init_object();
	obj->id = ft_strdup("pl");
	v1 = init_vect(0, -0.9, 0);
	v2 = init_vect(0, 0, 0);
	v3 = init_vect(255, 255, 255);
	obj->obj = init_pl(v1, v2, v3);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// plan 2
	obj = init_object();
	obj->id = ft_strdup("pl");
	v1 = init_vect(0, 0, -5);
	v2 = init_vect(0.5, 0, 0);
	v3 = init_vect(255, 255, 255);
	obj->obj = init_pl(v1, v2, v3);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// plan 3
	obj = init_object();
	obj->id = ft_strdup("pl");
	v1 = init_vect(-5, 0, 0);
	v2 = init_vect(0, 0, 0.5);
	v3 = init_vect(255, 255, 255);
	obj->obj = init_pl(v1, v2, v3);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// camera 1
	obj = init_object();
	obj->id = ft_strdup("c");
	v1 = init_vect(1, 1, 0);
	v2 = init_vect(-0.15, 0.2, 0);
	obj->obj = init_c(v1, v2, 90);
	((t_camera *)obj->obj)->is_used = 0;
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// camera 2
	obj = init_object();
	obj->id = ft_strdup("c");
	v1 = init_vect(0, 0.2, 0);
	v2 = init_vect(0, 0, 0);
	obj->obj = init_c(v1, v2, 90);
	((t_camera *)obj->obj)->is_used = 1;
	scene->current_cam = obj->obj;
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// camera 3
	obj = init_object();
	obj->id = ft_strdup("c");
	v1 = init_vect(-1, 1, 0);
	v2 = init_vect(-0.15, -0.2, 0);
	obj->obj = init_c(v1, v2, 90);
	((t_camera *)obj->obj)->is_used = 0;
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// light 1
	obj = init_object();
	obj->id = ft_strdup("l");
	v1 = init_vect(0, 2, -1.66);
	v2 = init_vect(255, 0, 0);
	obj->obj = init_l(v1, 1.1, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// light 2
	obj = init_object();
	obj->id = ft_strdup("l");
	v1 = init_vect(-0.66, 2, -1);
	v2 = init_vect(0, 255, 0);
	obj->obj = init_l(v1, 1.1, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// light 3
	obj = init_object();
	obj->id = ft_strdup("l");
	v1 = init_vect(0.66, 2, -1);
	v2 = init_vect(0, 0, 255);
	obj->obj = init_l(v1, 1.1, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// ambiant light
	v1 = init_vect(0, 0, 0);
	v2 = init_vect(255, 255, 255);
	l = init_l(v1, 0.4, v2);
	scene->ambiant = l;
	return (EXIT_SUCCESS);
}
*/
