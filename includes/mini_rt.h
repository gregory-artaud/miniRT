/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:03:52 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/22 19:46:50 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include <stdio.h>
# include <X11/X.h>
# include "mlx.h"
# include "libft.h"
# include "scene.h"
# include "objects.h"

# define KEY_ESC 65307

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
}				t_data;

void			error(char *s);
t_data			*init_data(char *file);
void			free_data(t_data *data);
void			set_hooks(t_data *vars);
int				key_pressed(int keycode, t_data *data);
int				exit_prog(t_data *data);
int				render(t_data *data);

#endif
