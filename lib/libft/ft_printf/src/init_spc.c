/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_spc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:24:31 by gartaud           #+#    #+#             */
/*   Updated: 2020/12/04 18:30:36 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		extract_nbr(t_print *p, int nbr_i, int *i)
{
	char	*tmp;
	int		res;

	res = 0;
	if (p->format[*i] == '*')
	{
		(*i)++;
		return ((int)va_arg(*(p->args), int));
	}
	while (ft_isdigit(p->format[*i]))
		(*i)++;
	tmp = ft_strndup(p->format + nbr_i, nbr_i - *i);
	if (!tmp || !*tmp)
		res = 0;
	else
		res = ft_atoi(tmp);
	free(tmp);
	return (res);
}

void	init_spc(t_print *p, int head)
{
	int		i;

	i = head;
	while (isflag(p->format[i]))
		i++;
	head = i;
	if (p->format[i] != '.')
		p->min_width = extract_nbr(p, head, &i);
	if (p->format[i] == '.')
	{
		head = ++i;
		p->precision = extract_nbr(p, head, &i);
	}
	p->type = p->format[i];
}
