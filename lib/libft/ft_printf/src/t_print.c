/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:28:39 by gartaud           #+#    #+#             */
/*   Updated: 2020/12/01 13:45:08 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*pinit(va_list *args, char *format)
{
	t_print	*new;

	new = malloc(sizeof(t_print));
	if (!new)
		return (0);
	new->args = args;
	new->format = format;
	new->out = malloc(sizeof(char) * 1);
	if (!(new->out))
		return (0);
	*(new->out) = 0;
	reset_spc(new);
	return (new);
}

void	pfree(t_print *p)
{
	free(p->out);
	free(p);
}

void	reset_spc(t_print *p)
{
	p->min_width = 0;
	p->precision = -1;
	p->type = 0;
	return ;
}
