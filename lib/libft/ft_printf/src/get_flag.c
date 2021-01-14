/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 22:40:45 by gartaud           #+#    #+#             */
/*   Updated: 2020/12/04 18:47:36 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_flag(t_print *p, int spc_i)
{
	char	res;

	res = 0;
	if (p->min_width < 0)
	{
		p->min_width *= -1;
		return ('-');
	}
	while (isflag(p->format[spc_i]))
	{
		if (p->format[spc_i] == '-')
			res = '-';
		else if (p->format[spc_i] == '0' && res != '-'
				&& p->precision == -1)
			res = '0';
		spc_i++;
	}
	return (res);
}
