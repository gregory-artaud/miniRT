/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:40:30 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/06 17:35:58 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static t_list		*go_to_current(t_list *lst, t_camera *current)
{
	t_list		*node;
	t_object	*obj;

	node = lst;
	while (node && node->content)
	{
		obj = (t_object *)node->content;
		if (is_camera(obj) && obj->obj == current)
			return (node);
		node = node->next;
	}
	return (NULL);
}

static t_camera		*get_next_cam(t_list *lst, t_camera *current)
{
	t_object	*obj;
	t_list		*node;

	obj = NULL;
	node = go_to_current(lst, current);
	if (!node)
		return (NULL);
	node = node->next;
	while (node && node->content)
	{
		obj = (t_object *)node->content;
		if (is_camera(obj) && !((t_camera *)obj->obj)->is_used)
			return ((t_camera *)obj->obj);
		node = node->next;
	}
	node = lst;
	while (node && node->content)
	{
		obj = (t_object *)node->content;
		if (is_camera(obj) && !((t_camera *)obj->obj)->is_used)
			return ((t_camera *)obj->obj);
		node = node->next;
	}
	return (NULL);
}

void				next_cam(t_data *data)
{
	t_camera	*cam;

	cam = get_next_cam(data->scene->obj, data->scene->current_cam);
	if (!cam || cam == data->scene->current_cam)
	{
		printf("Next camera not found !\n");
		return ;
	}
	data->scene->current_cam->is_used = 0;
	cam->is_used = 1;
	data->scene->current_cam = cam;
	printf("Camera switched !\nRendering...\n");
	if (render(data))
		error("Error during rendering.\n", data);
	printf("Image rendered !\n");
	return ;
}
