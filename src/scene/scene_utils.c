/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 20:18:26 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/23 22:42:45 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_camera		*get_camera(t_scene *scene)
{
	t_list	*node;
	
	print_scene(scene);
	if (!scene || !scene->obj || !scene->obj->content)
		return (NULL);
	node = scene->obj;
	while (node)
	{
		if (is_camera(node->content) && ((t_camera *)(node->content))->is_used)
			return (node->content);
		node = node->next;
	}
	return (NULL);
}
