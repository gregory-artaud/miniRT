/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:27:11 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/19 20:26:38 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_vect		*extract_color(char **s)
{
	int		len;
	t_vect	*res;

	len = ft_arrlen(s);
	if (len < LENGTH_COLOR)
		return (NULL);
	if (!ft_is_int(s[C_R]) || !ft_is_int(s[C_G]) || !ft_is_int(s[C_B]))
		return (NULL);
	res = init_vect(0, 0, 0);
	if (!res)
		return (NULL);
	res->x = (double)ft_atoi(s[C_R]);
	res->y = (double)ft_atoi(s[C_G]);
	res->z = (double)ft_atoi(s[C_B]);
	if (res->x < 0 || res->y < 0 || res->z < 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

t_vect		*extract_vect(char **s)
{
	int		len;
	t_vect	*res;

	len = ft_arrlen(s);
	if (len < LENGTH_VECTOR)
		return (NULL);
	if (!ft_is_double(s[V_X]) || !ft_is_double(s[V_Y])
		|| !ft_is_double(s[V_Z]))
		return (NULL);
	res = init_vect(0, 0, 0);
	if (!res)
		return (NULL);
	res->x = ft_atof(s[V_X]);
	res->y = ft_atof(s[V_Y]);
	res->z = ft_atof(s[V_Z]);
	return (res);
}
