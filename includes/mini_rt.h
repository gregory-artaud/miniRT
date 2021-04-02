/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:03:52 by gartaud           #+#    #+#             */
/*   Updated: 2021/04/02 07:38:18 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <pthread.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "objects.h"
# include "scene.h"
# include "bmp.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# define X11_KEY_PRESSED 2
# define X11_KEY_PRESSED_MASK 1L
# define X11_CLIENT_MSG 17
# define X11_BTN_RELEASE_MASK 131072
# define NB_ID 10
# define KEY_ESC 53
# define KEY_NEXT_CAM 8
/*
** OPTIONS
*/
# define MIRROR_DEPTH 2
# define SAMPLING 2
# define NUM_THREAD 4

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	int			save;
}				t_mlx;
typedef struct s_data
{
	t_mlx		*mlx;
	t_scene		*scene;
	t_bmp		*bmp;
}				t_data;
typedef struct s_ssaa
{
	t_data		*data;
	t_vect		***px;
	int			start;
	int			end;
}				t_ssaa;

/*
** mini_rt.c
*/
void			error(char *s, t_data *data);
/*
** init_mlx.c
*/
int				check_scene(t_data *data);
void			free_mlx(t_mlx *mlx);
void			*init_mlx(t_data *data, int save);
/*
** init_data.c
*/
t_data			*init_data(char *file, int save);
void			free_data(t_data *data);
/*
** hooks.c
*/
void			set_hooks(t_data *vars);
int				key_pressed(int keycode, t_data *data);
int				exit_prog(t_data *data);
/*
** ray_tracing.c
*/
t_ray			*gen_primary_ray(int x, int y, t_data *data);
t_ray			*gen_shadow_ray(t_vect *pos, t_vect *target);
/*
** render.c
*/
void			print_progress(int x, int end);
void			draw(t_data *data, int x, int y, t_vect *c);
t_vect			*trace(t_ray *r, t_scene *scene, int depth);
int				render(t_data *data);
/*
** ssaa.c and ssaa_utils.c
*/
void			free_px(t_vect ***px, t_data *data);
void			draw_pixels(t_vect ***px, t_data *data);
void			init_arg(t_ssaa *arg[NUM_THREAD], t_data *data);
int				render_ssaa(t_data *data);
/*
** next_cam.c
*/
void			next_cam(t_data *data);
t_vect			*parse_lights(t_ray *ray, t_vect *hit, t_vect *normal,
					t_scene *scene);
#endif
