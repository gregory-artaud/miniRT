/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:03:52 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/18 14:34:13 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "mlx.h"
# include "libft.h"
# include "algebra.h"

# define PR_KEY 2
# define CLI_MSG 33
# define MK_PR_KEY 1L<<0
# define MK_RE_BTN 1L<<3

# define LX_KEY_ESC 65307
# define MC_KEY_ESC 53

# define WIN_NAME "miniRT"
# define WIN_W 960
# define WIN_H 540

typedef struct	s_camera
{
	t_point		pos;
	t_vect		ori;
	double		fov;

}				t_camera;
typedef struct 	s_scene
{
	t_camera	*current_cam;
	t_list		*objects;
	t_list		*cameras;
	t_list		*lights;

}				t_scene;
typedef struct  s_mlx {
        void    *mlx;
        void    *win;
		int		win_w;
		int		win_h;
		int		save;
}               t_mlx;
typedef struct 	s_data
{
	t_scene		*scene;
	t_mlx		*mlx;
}				t_data;

typedef struct	s_light
{
	t_point		pos;
	int			a;
	int			r;
	int			g;
	int			b;
}				t_light;
typedef struct	s_object
{
	char		*id;
	void		*obj;


}				t_object;
typedef t_line	t_ray;
/*
** init.c
*/
void			set_hooks(t_data *data);
t_mlx			*init_mlx(void);
t_scene			*init_scene(char *file);
t_data			*init_data();
/*
** keyboard_hook.c
*/
int				key_pressed(int keycode, t_mlx *vars);
/*
** exit_prog.c
*/
int				exit_prog(int keycode, t_mlx *vars);
void			free_scene(t_scene *scene);
/*
** render.c
*/
int				render(t_data *data);
/*
** ray_tracing.c
*/
t_ray			*get_ray(t_camera *cam, int x, int y);
int				trace(t_ray *ray, t_scene *scene);
/*
** rt_file_parser.c
*/
int				detect_rt(char *file);

#endif
