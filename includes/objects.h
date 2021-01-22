/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:32:22 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/22 22:11:28 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_object
{
	char		*id;
	void		*obj;
}				t_object;

typedef struct	s_vect
{
	double		x;
	double		y;
	double		z;
}				t_vect;

typedef struct	s_sphere
{
	t_vect		*pos;
	t_vect		*color;
	double		diameter;
}				t_sphere;

typedef struct	s_light
{
	t_vect		*pos;
	t_vect		*color;
	double		lum;
}				t_light;

typedef struct	s_camera
{
	t_vect		*pos;
	t_vect		*ori;
	double		fov;
}				t_camera;

t_object		*init_object(void);
t_vect			*init_vect(double x, double y, double z);
t_sphere		*init_sp(t_vect *pos, double diameter, t_vect *color);
t_light			*init_l(t_vect *pos, double lum, t_vect *color);
t_camera		*init_c(t_vect *pos, t_vect *ori, double fov);
void			free_c(t_camera *c);
void			free_sp(t_sphere *sp);
void			free_l(t_light *l);
void			free_object(void *ptr);

#endif
