/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_def.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:55:08 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/24 17:56:14 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_DEF_H
# define OBJECTS_DEF_H

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

typedef struct	s_plan
{
	t_vect		*pos;
	t_vect		*normal;
	t_vect		*color;
}				t_plan;

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
	double		matrix[3][3];
	double		fov;
	int			is_used;
}				t_camera;

#endif
