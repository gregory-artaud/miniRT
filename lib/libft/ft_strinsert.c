/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:18:57 by gartaud           #+#    #+#             */
/*   Updated: 2020/12/04 17:52:14 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strinsert(char **s, int i, char c)
{
	int		ln;
	char	*res;

	if (!*s)
		return ;
	ln = ft_strlen(*s);
	if (!(res = ft_calloc(ln + 2, 1)))
		return ;
	ft_memcpy(res, *s, i);
	res[i] = c;
	ft_memcpy(res + i + 1, *s + i, ln - i);
	free(*s);
	*s = res;
	return ;
}
