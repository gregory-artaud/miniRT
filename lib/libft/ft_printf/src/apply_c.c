/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:32:22 by gartaud           #+#    #+#             */
/*   Updated: 2020/12/10 13:46:01 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	bypass_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	i++;
	while (s[i])
		i++;
	return (i);
}

int			apply_c(char **dest, t_print *p, int spc_i)
{
	unsigned char	c;
	char			flag;

	c = (unsigned char)va_arg(*(p->args), int);
	flag = get_flag(p, spc_i);
	if (!p->min_width)
		p->min_width++;
	if (!(*dest = ft_calloc(p->min_width + 1, 1)))
		return (0);
	ft_memset(*dest, ' ', p->min_width);
	if (!flag)
		(*dest)[p->min_width - 1] = c;
	else if (flag == '-')
		*dest[0] = c;
	else if (flag == '0')
	{
		ft_memset(*dest, '0', p->min_width);
		(*dest)[p->min_width - 1] = c;
	}
	if (!c)
		return (bypass_strlen(*dest));
	return (ft_strlen(*dest));
}
