/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:18:55 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/16 16:19:31 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_DEF_H
# define PARSER_DEF_H

# define SEPARATORS ", \n\t\v\f\r"

/*
** Color
*/
# define LENGTH_COLOR 3
# define R 0
# define G 1
# define B 2

/*
** Resolution
*/
# define LENGTH_R_INFOS 3
# define OFFSET_R_W 1
# define OFFSET_R_H 2
/*
** Camera
*/
# define LENGTH_C_INFOS 12
# define OFFSET_C_POS 1
# define OFFSET_C_ORI 6
# define OFFSET_C_FOV 11
/*
** Ambiant light
*/
# define LENGTH_A_INFOS 5
# define OFFSET_A_INTENSITY 1
# define OFFSET_A_COLOR 2
/*
** Triangle
*/
# define LENGTH_TR_INFOS 21
# define OFFSET_TR_P1 1
# define OFFSET_TR_P2 6
# define OFFSET_TR_P3 11
# define OFFSET_TR_COLOR 16

#endif
