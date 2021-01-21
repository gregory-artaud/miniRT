/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:57:54 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/21 19:44:22 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <stdlib.h>

typedef struct	s_scene
{
	int			r_w;
	int			r_h;
}				t_scene;
t_scene			*init_scene(void);
void			free_scene(t_scene *scene);
#endif
