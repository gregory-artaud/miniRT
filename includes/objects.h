/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:32:22 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/24 01:05:41 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
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

typedef struct	s_ray
{
	t_vect		*pos;
	t_vect		*dir;
}				t_ray;

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
	int			is_used;
}				t_camera;

t_object		*init_object(void);
t_vect			*init_vect(double x, double y, double z);
t_sphere		*init_sp(t_vect *pos, double diameter, t_vect *color);
t_light			*init_l(t_vect *pos, double lum, t_vect *color);
t_camera		*init_c(t_vect *pos, t_vect *ori, double fov);
t_ray			*init_ray(t_vect *pos, t_vect *dir);
void			free_ray(t_ray *ray);
void			free_c(t_camera *c);
void			free_sp(t_sphere *sp);
void			free_l(t_light *l);
void			free_object(void *ptr);
int				is_camera(t_object *obj);
int				is_sphere(t_object *obj);
t_vect			*dup_vect(t_vect *u);
t_vect			*minus_vect(t_vect *u, t_vect *v);
double			v_lenght(t_vect *u);
void			normalize(t_vect *u);
double			v_dot(t_vect *u, t_vect *v);

#endif
