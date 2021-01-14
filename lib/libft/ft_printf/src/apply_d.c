/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:32:22 by gartaud           #+#    #+#             */
/*   Updated: 2020/12/10 11:28:41 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_d(char **dest, t_print *p, int spc_i)
{
	long int	arg;
	int			is_neg;

	arg = (int)va_arg(*(p->args), int);
	is_neg = (arg < 0);
	if (!arg && !p->precision)
		*dest = ft_strdup("");
	else
		*dest = ft_itoa_base(ft_abs(arg), "0123456789");
	if (!dest)
		return (0);
	apply_flags_nb(dest, p, spc_i, is_neg);
	if (arg < 0)
		insert_minus(dest);
	return (ft_strlen(*dest));
}
