/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:03:52 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/17 19:08:49 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "libft.h"
# include <X11/X.h>

# define KEY_ESC 65307
# define WIN_NAME "miniRT"

typedef struct  s_vars {
        void    *mlx;
        void    *win;
		int		win_w;
		int		win_h;
}               t_vars;

/*
** init.c
*/
int		init(t_vars **vars);
void	set_hooks(t_vars *vars);
/*
** keyboard_hook.c
*/
int	key_pressed(int keycode, t_vars *vars);
/*
**
*/
int	exit_prog(int keycode, t_vars *vars);

#endif