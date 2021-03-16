/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:27:11 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/16 16:23:15 by gartaud          ###   ########lyon.fr   */
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
	if (!ft_is_int(s[R]) || !ft_is_int(s[G]) || !ft_is_int(s[B]))
		return (NULL);
	res = init_vect(0, 0, 0);
	if (!res)
		return (NULL);
	res->x = (double)ft_atoi(s[R]);
	res->y = (double)ft_atoi(s[G]);
	res->z = (double)ft_atoi(s[B]);
	if (res->x < 0 || res->y < 0 || res->z < 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
