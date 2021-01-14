/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 11:23:59 by gartaud           #+#    #+#             */
/*   Updated: 2020/11/23 11:26:56 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*my_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	char			*str;

	str = (char *)s;
	i = -1;
	while (++i < n)
		str[i] = (char)c;
	return (s);
}

static void	my_bzero(void *s, size_t n)
{
	my_memset(s, 0, n);
}

void		*ft_calloc(size_t nmemb, size_t size)
{
	void *ptr;

	ptr = malloc(size * nmemb);
	if (!ptr)
		return (0);
	my_bzero(ptr, size * nmemb);
	return (ptr);
}
