/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_spc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:48:06 by gartaud           #+#    #+#             */
/*   Updated: 2020/12/04 17:39:20 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_ft_tab(int (*process[CONVERSION_NB])(char **, t_print *, int))
{
	process[0] = apply_c;
	process[1] = apply_s;
	process[2] = apply_p;
	process[3] = apply_d;
	process[4] = apply_u;
	process[5] = apply_x;
	process[6] = apply_big_x;
	process[7] = apply_percent;
}

int		type_to_index(char c)
{
	if (c == 'c')
		return (0);
	else if (c == 's')
		return (1);
	else if (c == 'p')
		return (2);
	else if ((c == 'd') || (c == 'i'))
		return (3);
	else if (c == 'u')
		return (4);
	else if (c == 'x')
		return (5);
	else if (c == 'X')
		return (6);
	else if (c == '%')
		return (7);
	else
		return (-1);
}

int		process_spc(char **dest, t_print *p, int spc_i)
{
	int		(*process[CONVERSION_NB])(char **, t_print *, int);
	int		index;

	init_ft_tab(process);
	index = type_to_index(p->type);
	if (index > -1)
		return (process[index](dest, p, spc_i));
	return (0);
}
