/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:57:54 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/22 19:55:47 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <stdlib.h>
# include "libft.h"
# include "objects.h"

typedef struct	s_scene
{
	int			r_w;
	int			r_h;
	t_list		*obj;
}				t_scene;
t_scene			*init_scene(void);
int				fill_scene(t_scene *scene, char *file);
void			free_scene(t_scene *scene);
void			print_scene(t_scene *scene);
#endif
