/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:03:52 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/06 17:34:59 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include <stdio.h>
# include <math.h>
# include <X11/X.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "objects.h"
# include "scene.h"
# include "bmp.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# define NB_ID 10
# define KEY_ESC 65307
# define KEY_NEXT_CAM 99
# define MIRROR_DEPTH 2

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			save;
}				t_mlx;
typedef struct	s_data
{
	t_mlx		*mlx;
	t_scene		*scene;
	t_bmp		*bmp;
}				t_data;

void			print_c(t_camera *c);
void			print_sp(t_sphere *sp);
void			error(char *s, t_data *data);
t_data			*init_data(char *file, int save);
void			free_data(t_data *data);
void			set_hooks(t_data *vars);
int				key_pressed(int keycode, t_data *data);
int				parse_file(t_scene *scene, char *file);
int				exit_prog(t_data *data);
t_ray			*gen_primary_ray(int x, int y, t_data *data);
t_ray			*gen_shadow_ray(t_vect *pos, t_vect *target);
int				render(t_data *data);
void			next_cam(t_data *data);
t_vect			*parse_lights(t_ray *ray, t_vect *hit, t_vect *normal,
								t_scene *scene);

#endif
