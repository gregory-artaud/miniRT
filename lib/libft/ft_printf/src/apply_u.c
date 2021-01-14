/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:32:22 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/14 13:48:35 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_u(char **dest, t_print *p, int spc_i)
{
	unsigned int	arg;

	arg = (unsigned int)va_arg(*(p->args), unsigned int);
	if (!arg && !p->precision)
		*dest = ft_strdup("");
	else
		*dest = ft_itoa_base(ft_abs(arg), "0123456789");
	if (!dest)
		return (0);
	apply_flags_nb(dest, p, spc_i, 0);
	return (ft_strlen(*dest));
}
