/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 07:48:25 by gartaud           #+#    #+#             */
/*   Updated: 2020/11/18 17:03:29 by gartaud          ###   ########lyon.fr   */
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

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	slen;
	unsigned int	sublen;
	unsigned int	i;

	if (!s)
		return (0);
	slen = my_strlen(s);
	if (start >= slen)
		start = slen;
	sublen = (slen < len) ? slen : len;
	substr = (char *)malloc(sizeof(char) * (sublen + 1));
	if (!substr)
		return (0);
	i = -1;
	while (++i < sublen)
		substr[i] = s[i + start];
	substr[i] = 0;
	return (substr);
}
