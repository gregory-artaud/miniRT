/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:13:12 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/07 14:15:49 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_double(char *s)
{
	if (!s || !*s)
		return (0);
	while (*s && ft_isdigit(*s))
		s++;
	if (!*s)
		return (1);
	if (*s != '.' || !*(++s))
		return (0);
	while (*s && ft_isdigit(*s))
		s++;
	return (!*s);
}
