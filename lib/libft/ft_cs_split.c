/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:39:41 by gartaud           #+#    #+#             */
/*   Updated: 2021/03/03 13:14:41 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*my_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*d;
	char			*s;

	d = (char *)dest;
	s = (char *)src;
	i = -1;
	while (++i < n)
		d[i] = s[i];
	return (dest);
}

static char		*my_strndup(char const *s, size_t n)
{
	char *res;

	res = malloc(sizeof(char) * n + 1);
	my_memcpy(res, s, n);
	res[n] = 0;
	return (res);
}

static int		ft_count_words(char const *s, char *charset)
{
	int				word_count;
	unsigned int	i;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (ft_strchr(charset, s[i]))
			i++;
		if (s[i])
			word_count++;
		while (s[i] && !ft_strchr(charset, s[i]))
			i++;
	}
	return (word_count);
}

char			**ft_cs_split(char const *s, char *charset)
{
	char			**res;
	unsigned int	i;
	unsigned int	j;
	unsigned int	word_start_i;

	if (!s)
		return (0);
	res = malloc(sizeof(char *) * ((ft_count_words(s, charset) + 1)));
	if (!res)
		return (0);
	i = 0;
	j = 0;
	word_start_i = 0;
	while (s[i])
	{
		while (ft_strchr(charset, s[i]))
			i++;
		word_start_i = i;
		while (s[i] && !ft_strchr(charset, s[i]))
			i++;
		if (i > word_start_i)
			res[j++] = my_strndup(s + word_start_i, i - word_start_i);
	}
	res[j] = NULL;
	return (res);
}
