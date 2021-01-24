/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:57:25 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/23 22:54:25 by gartaud          ###   ########lyon.fr   */
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
	scene->current_cam = 0;
	scene->obj = ft_lstnew(NULL);
	return (scene);
}

void			free_scene(t_scene *scene, void (*del)(void *))
{
	ft_lstclear(&(scene->obj), del);
	free(scene);
	return ;
}
