/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:57:54 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/02 18:16:53 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <stdlib.h>
# include "objects.h"
# include "libft.h"

typedef struct	s_scene
{
	int			r_w;
	int			r_h;
	t_camera	*current_cam;
	t_list		*obj;
}				t_scene;
t_scene			*init_scene(void);
void			free_scene(t_scene *scene, void (*del)(void *));
void			print_scene(t_scene *scene);
void			print_obj(void *ptr);
#endif
