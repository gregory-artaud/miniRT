/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:32:22 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/14 13:47:56 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_head(char **dest)
{
	char	*tmp;

	tmp = ft_strdup("0x");
	ft_strmcat(&tmp, *dest);
	free(*dest);
	*dest = tmp;
	return ;
}

int		apply_p(char **dest, t_print *p, int spc_i)
{
	unsigned long long	arg;
	char				*tmp;

	arg = (unsigned long long)va_arg(*(p->args), unsigned long long);
	if (arg == ULONG_MAX && (*dest = ft_strdup("0xffffffffffffffff")))
		return (ft_strlen(*dest));
	if (!arg && !p->precision)
		*dest = ft_strdup("");
	else
		*dest = ft_itoa_base(ft_abs(arg), "0123456789abcdef");
	if (!dest)
		return (0);
	if (**dest == '-')
	{
		tmp = ft_strdup(*dest + 1);
		free(*dest);
		*dest = tmp;
	}
	set_head(dest);
	apply_flags_nb(dest, p, spc_i, 0);
	return (ft_strlen(*dest));
}
