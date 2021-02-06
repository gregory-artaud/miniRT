/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:57:25 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/05 18:08:29 by gartaud          ###   ########lyon.fr   */
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
	scene->current_cam = NULL;
	scene->ambiant = NULL;
	scene->obj = ft_lstnew(NULL);
	return (scene);
}

void			free_scene(t_scene *scene, void (*del)(void *))
{
	if (!scene)
		return ;
	if (scene->ambiant)
		free_l(scene->ambiant);
	ft_lstclear(&(scene->obj), del);
	free(scene);
	return ;
}
