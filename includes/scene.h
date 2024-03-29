/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:57:54 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 15:40:06 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <stdlib.h>
# include "objects.h"
# include "libft.h"
# include "parser_def.h"

typedef struct s_scene
{
	int			r_w;
	int			r_h;
	t_camera	*current_cam;
	t_light		*ambiant;
	t_list		*obj;
}				t_scene;

t_scene			*init_scene(void);
void			free_scene(t_scene *scene, void (*del)(void *));
void			push_obj(char *id, void *obj, t_scene *scene);
/*
** Parsing
*/
int				parse_file(t_scene *scene, char *file);
int				set_resolution(t_scene *scene, char **infos);
int				set_ambiant(t_scene *scene, char **infos);
int				add_camera(t_scene *scene, char **infos);
int				add_light(t_scene *scene, char **infos);
int				add_sphere(t_scene *scene, char **infos);
int				add_plane(t_scene *scene, char **infos);
int				add_square(t_scene *scene, char **infos);
int				add_cylinder(t_scene *scene, char **infos);
int				add_triangle(t_scene *scene, char **infos);
int				add_circle(t_scene *scene, char **infos);
/*
** Parsing utils
*/
t_vect			*extract_color(char **s);
t_vect			*extract_vect(char **s);
#endif
