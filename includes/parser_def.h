/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:18:55 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/27 15:56:33 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_DEF_H
# define PARSER_DEF_H

# define SEPARATORS ", \n\t\v\f\r"
/*
** Global
*/
# define SINGLE_LINE_COMMENT "#"
/*
** Color
*/
# define LENGTH_COLOR 3
# define COLOR_MIN 0
# define COLOR_MAX 255
# define C_R 0
# define C_G 1
# define C_B 2
/*
** Vector
*/
# define LENGTH_VECTOR 3
# define V_X 0
# define V_Y 1
# define V_Z 2
# define V_ORI_MIN -1.0
# define V_ORI_MAX 1.0
/*
** Resolution
*/
# define R_ID "R"
# define R_ID_LN 2
# define LENGTH_R_INFOS 3
# define OFFSET_R_W 1
# define OFFSET_R_H 2
/*
** Camera
*/
# define C_ID "c"
# define C_ID_LN 2
# define LENGTH_C_INFOS 8
# define OFFSET_C_POS 1
# define OFFSET_C_ORI 4
# define OFFSET_C_FOV 7
# define C_FOV_MIN 0
# define C_FOV_MAX 180

typedef struct s_cam
{
	t_vect		*pos;
	t_vect		*ori;
	double		fov;
}				t_cam;
/*
** Ambiant light
*/
# define A_ID "A"
# define A_ID_LN 2
# define LENGTH_A_INFOS 5
# define OFFSET_A_INTENSITY 1
# define OFFSET_A_COLOR 2

typedef struct s_ambiant
{
	double			lum;
	t_vect			*color;
}					t_ambiant;
/*
** Light
*/
# define L_ID "l"
# define L_ID_LN 2
# define LENGTH_L_INFOS 8
# define OFFSET_L_POS 1
# define OFFSET_L_INTENSITY 4
# define OFFSET_L_COLOR 5

typedef struct s_l
{
	t_vect		*pos;
	double		lum;
	t_vect		*color;
}				t_l;
/*
** Triangle
*/
# define TR_ID "tr"
# define TR_ID_LN 3
# define LENGTH_TR_INFOS 13
# define OFFSET_TR_P1 1
# define OFFSET_TR_P2 4
# define OFFSET_TR_P3 7
# define OFFSET_TR_COLOR 10

typedef struct s_tr
{
	t_vect		*p1;
	t_vect		*p2;
	t_vect		*p3;
	t_vect		*color;
}				t_tr;
/*
** Plane
*/
# define PL_ID "pl"
# define PL_ID_LN 3
# define LENGTH_PL_INFOS 10
# define OFFSET_PL_POS 1
# define OFFSET_PL_ORI 4
# define OFFSET_PL_COLOR 7

typedef struct s_pl
{
	t_vect		*pos;
	t_vect		*ori;
	t_vect		*color;
}				t_pl;
/*
** Sphere
*/
# define SP_ID "sp"
# define SP_ID_LN 3
# define LENGTH_SP_INFOS 8
# define OFFSET_SP_POS 1
# define OFFSET_SP_DIAMETER 4
# define OFFSET_SP_COLOR 5

typedef struct s_sp
{
	t_vect		*pos;
	double		diameter;
	t_vect		*color;
}				t_sp;
/*
** Square
*/
# define SQ_ID "sq"
# define SQ_ID_LN 3
# define LENGTH_SQ_INFOS 11
# define OFFSET_SQ_POS 1
# define OFFSET_SQ_ORI 4
# define OFFSET_SQ_SIZE 7
# define OFFSET_SQ_COLOR 8

typedef struct s_sq
{
	t_vect		*pos;
	t_vect		*ori;
	double		size;
	t_vect		*color;
}				t_sq;
/*
** Circle
*/
# define CI_ID "ci"
# define CI_ID_LN 3
# define LENGTH_CI_INFOS 11
# define OFFSET_CI_POS 1
# define OFFSET_CI_ORI 4
# define OFFSET_CI_DIAMETER 7
# define OFFSET_CI_COLOR 8

typedef struct s_ci
{
	t_vect		*pos;
	t_vect		*ori;
	double		diameter;
	t_vect		*color;
}				t_ci;
/*
** Cylinder
*/
# define CY_ID "cy"
# define CY_ID_LN 3
# define LENGTH_CY_INFOS 12
# define OFFSET_CY_POS 1
# define OFFSET_CY_ORI 4
# define OFFSET_CY_DIAMETER 7
# define OFFSET_CY_HEIGHT 8
# define OFFSET_CY_COLOR 9

typedef struct s_cy
{
	t_ray		*pos_and_ori;
	double		diameter;
	double		height;
	t_vect		*color;
}				t_cy;
#endif
