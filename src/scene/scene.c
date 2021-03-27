/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:57:25 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 15:00:53 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "scene.h"

t_scene	*init_scene(void)
{
	t_scene		*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->r_w = -1;
	scene->r_h = -1;
	scene->current_cam = NULL;
	scene->ambiant = NULL;
	scene->obj = ft_lstnew(NULL);
	return (scene);
}

void	free_scene(t_scene *scene, void (*del)(void *))
{
	if (!scene)
		return ;
	if (scene->ambiant)
		free_l(scene->ambiant);
	ft_lstclear(&(scene->obj), del);
	free(scene);
	return ;
}

void	push_obj(char *id, void *obj, t_scene *scene)
{
	t_object	*new;

	new = init_object();
	new->id = id;
	new->obj = obj;
	ft_lstadd_front(&(scene->obj), ft_lstnew(new));
	return ;
}
