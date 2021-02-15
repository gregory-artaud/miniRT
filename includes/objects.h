/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:32:22 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/15 15:27:08 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"

# define EPSILON 1e-5
# define K_A 0.3
# define K_D 1.6
# define K_S 2.0
# define N_S 25

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
	double		matrix[3][3];
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
int				is_light(t_object *obj);
t_vect			*dup_vect(t_vect *u);
t_vect			*v_minus(t_vect *u, t_vect *v);
double			v_length(t_vect *u);
void			normalize(t_vect *u);
double			v_dot(t_vect *u, t_vect *v);
t_vect			*v_mult(double k, t_vect *u);
t_vect			*v_add(t_vect *u, t_vect *v);
t_vect			*obj_get_color(t_object *obj);
int				c_to_hex(t_vect *c);
double			intersect_sp(t_ray *ray, t_sphere *sp);
int				solve_quadratic(double a, double b, double c, double *sol);
t_vect			*get_normal(t_ray *ray, t_vect *hit, t_object *obj);
t_vect			*get_normal_sp(t_ray *ray, t_vect *hit, t_sphere *sp);
void			v_fadd(t_vect *u, t_vect *v);
t_vect			*v_bisect(t_vect *u, t_vect *v);
double			v_cmp(t_vect *u, t_vect *v);
t_vect			*v_vmult(t_vect *u, t_vect *v);
void			translate(t_vect *u, double k, t_vect *v);
void			put_in_range(t_vect *u, double min, double max);
double			intersect(t_ray *ray, t_list *lst, t_object **obj);
int				is_ray_blocked(t_ray *ray, t_list *lst, t_light *l);
void			v_cos(t_vect *u);
void			v_sin(t_vect *u);
void			apply_matrix(t_vect *u, double m[3][3]);
#endif
