/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:32:22 by gartaud           #+#    #+#             */
/*   Updated: 2021/02/24 17:56:39 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include "objects_def.h"

# define EPSILON 1e-6
# define K_A 0.1
# define K_D 1.5
# define K_S 0.9
# define N_S 30

t_object		*init_object(void);
void			free_object(void *ptr);
t_vect			*obj_get_color(t_object *obj);
int				c_to_hex(t_vect *c);
int				solve_quadratic(double a, double b, double c, double *sol);
t_vect			*get_normal(t_ray *ray, t_vect *hit, t_object *obj);
double			intersect(t_ray *ray, t_list *lst, t_object **obj);
/*
** Light
*/
t_light			*init_l(t_vect *pos, double lum, t_vect *color);
void			free_l(t_light *l);
int				is_light(t_object *obj);
/*
** Ray
*/
int				is_ray_blocked(t_ray *ray, t_list *lst, t_light *l);
t_ray			*init_ray(t_vect *pos, t_vect *dir);
void			free_ray(t_ray *ray);
/*
** Camera
*/
t_camera		*init_c(t_vect *pos, t_vect *ori, double fov);
void			free_c(t_camera *c);
int				is_camera(t_object *obj);
/*
** Sphere
*/
double			intersect_sp(t_ray *ray, t_sphere *sp);
t_sphere		*init_sp(t_vect *pos, double diameter, t_vect *color);
t_vect			*get_normal_sp(t_ray *ray, t_vect *hit, t_sphere *sp);
int				is_sphere(t_object *obj);
void			free_sp(t_sphere *sp);
/*
** Plan
*/
t_plan			*init_pl(t_vect *pos, t_vect *ori, t_vect *color);
void			free_pl(t_plan *pl);
int				is_plan(t_object *obj);
t_vect			*get_normal_pl(t_ray *ray, t_vect *hit, t_plan *pl);
double			intersect_pl(t_ray *ray, t_plan *pl);
/*
** Matrix
*/
void			apply_matrix(t_vect *u, double m[3][3]);
void			calc_rot(double m[3][3], t_vect *angles);
/*
** Vector
*/
t_vect			*init_vect(double x, double y, double z);
void			translate(t_vect *u, double k, t_vect *v);
void			v_cos(t_vect *u);
void			v_sin(t_vect *u);
void			v_fadd(t_vect *u, t_vect *v);
void			put_in_range(t_vect *u, double min, double max);
t_vect			*v_bisect(t_vect *u, t_vect *v);
double			v_cmp(t_vect *u, t_vect *v);
t_vect			*v_vmult(t_vect *u, t_vect *v);
t_vect			*dup_vect(t_vect *u);
t_vect			*v_minus(t_vect *u, t_vect *v);
double			v_length(t_vect *u);
void			normalize(t_vect *u);
double			v_dot(t_vect *u, t_vect *v);
t_vect			*v_mult(double k, t_vect *u);
t_vect			*v_add(t_vect *u, t_vect *v);
#endif
