/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 09:26:02 by gartaud           #+#    #+#             */
/*   Updated: 2020/12/04 17:52:33 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	my_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			slen;

	slen = my_strlen(src);
	if (size != 0)
	{
		i = 0;
		while ((i < size - 1) && (i < slen))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (slen);
}

static size_t	my_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while ((dst[i]) && (i < size))
		i++;
	while ((src[j]) && ((i + j + 1) < size))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != size)
		dst[i + j] = 0;
	return (i + my_strlen(src));
}

void			ft_strmcat(char **s1, char *s2)
{
	char	*res;
	int		res_ln;
	int		s1_ln;

	if (!*s1)
		s1_ln = 0;
	else
		s1_ln = my_strlen(*s1);
	res_ln = s1_ln + my_strlen(s2);
	if (!(res = ft_calloc(res_ln + 1, 1)))
		return ;
	my_strlcpy(res, *s1, s1_ln + 1);
	my_strlcat(res, s2, res_ln + 1);
	free(*s1);
	*s1 = res;
	return ;
}
