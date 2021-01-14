/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:32:22 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/11 15:52:50 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_s(char **dest, t_print *p, int spc_i)
{
	char	*str;
	int		flag;
	int		null;

	str = (char *)va_arg(*(p->args), char *);
	flag = get_flag(p, spc_i);
	null = 0;
	if (!str && (null = 1))
		str = ft_strdup("(null)");
	if (p->precision >= 0)
		*dest = ft_strndup(str, p->precision);
	else
		*dest = ft_strdup(str);
	if (null)
		free(str);
	if ((int)ft_strlen(*dest) < p->min_width)
	{
		if (flag == '-')
			ft_strpad(dest, LFT_RIGHT, p->min_width, ' ');
		else
			ft_strpad(dest, LFT_LEFT, p->min_width, ' ');
	}
	return (ft_strlen(*dest));
}
