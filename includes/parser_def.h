/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:18:55 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/22 11:17:25 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_DEF_H
# define PARSER_DEF_H

# define SEPARATORS ", \n\t\v\f\r"

/*
** Global
*/
# define SINGLE_LINE_COMMENT "//"
/*
** Color
*/
# define LENGTH_COLOR 3
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
# define LENGTH_R_INFOS 3
# define OFFSET_R_W 1
# define OFFSET_R_H 2
/*
** Camera
*/
# define C_ID "c"
# define LENGTH_C_INFOS 8
# define OFFSET_C_POS 1
# define OFFSET_C_ORI 4
# define OFFSET_C_FOV 7
# define C_FOV_MIN 0
# define C_FOV_MAX 180
/*
** Ambiant light
*/
# define A_ID "A"
# define LENGTH_A_INFOS 5
# define OFFSET_A_INTENSITY 1
# define OFFSET_A_COLOR 2
/*
** Light
*/
# define L_ID "l"
# define LENGTH_L_INFOS 8
# define OFFSET_L_POS 1
# define OFFSET_L_INTENSITY 4
# define OFFSET_L_COLOR 5
/*
** Triangle
*/
# define TR_ID "tr"
# define LENGTH_TR_INFOS 13
# define OFFSET_TR_P1 1
# define OFFSET_TR_P2 4
# define OFFSET_TR_P3 7
# define OFFSET_TR_COLOR 10
/*
** Plane
*/
# define PL_ID "pl"
# define LENGTH_PL_INFOS 10
# define OFFSET_PL_POS 1
# define OFFSET_PL_ORI 4
# define OFFSET_PL_COLOR 7
/*
** Sphere
*/
# define SP_ID "sp"
# define LENGTH_SP_INFOS 8
# define OFFSET_SP_POS 1
# define OFFSET_SP_DIAMETER 4
# define OFFSET_SP_COLOR 5
#endif
