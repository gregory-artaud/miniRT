/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:40:19 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/18 14:32:23 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGEBRA_H
# define ALGEBRA_H

# define PREC 1e-5

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;
typedef	t_point	t_vect;
typedef struct	s_sphere
{
	t_point		pos;
	double		rad;
}				t_sphere;
typedef struct	s_line
{
	t_point		orig;
	t_vect		dir;
}				t_line;

#endif
