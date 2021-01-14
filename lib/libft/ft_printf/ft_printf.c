/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:38:44 by gartaud           #+#    #+#             */
/*   Updated: 2020/12/04 10:49:07 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	t_print	*p;
	va_list	args;
	int		res_ln;
	int		i;

	va_start(args, s);
	p = pinit(&args, (char *)s);
	i = -1;
	res_ln = 0;
	while (s[++i])
		if (s[i] == '%')
			res_ln += convert(p, &i);
		else
			res_ln += fill(p, &i);
	pfree(p);
	va_end(args);
	return (res_ln);
}
