/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:12:27 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/24 01:32:59 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "mini_rt.h"

int				fill_scene(t_scene *scene, char *file)
{
	t_object	*obj;
	t_vect		*v1;
	t_vect		*v2;

	(void)file;
	scene->r_w = 300;
	scene->r_h = 300;
	// sphere
	obj = init_object();
	obj->id = ft_strdup("sp");
	v1 = init_vect(0, 0, -50);
	v2 = init_vect(255, 0, 0);
	obj->obj = init_sp(v1, 1, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// camera
	obj = init_object();
	obj->id = ft_strdup("c");
	v1 = init_vect(0, 0, 0);
	v2 = init_vect(0, 0, 0);
	obj->obj = init_c(v1, v2, 75);
	((t_camera *)obj->obj)->is_used = 1;
	scene->current_cam = obj->obj;
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	// light
	obj = init_object();
	obj->id = ft_strdup("l");
	v1 = init_vect(0, 0, 0);
	v2 = init_vect(255, 255, 255);
	obj->obj = init_l(v1, 0.7, v2);
	ft_lstadd_front(&(scene->obj), ft_lstnew(obj));
	return (EXIT_SUCCESS);
}
