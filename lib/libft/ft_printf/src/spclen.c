/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spclen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:08:29 by gartaud           #+#    #+#             */
/*   Updated: 2020/12/10 11:18:40 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		isflag(char c)
{
	return ((c == '-') || (c == '0') || (c == ' '));
}

int		isconvert(char c)
{
	return ((c == 'c') || (c == 's')
			|| (c == 'p') || (c == 'd')
			|| (c == 'i') || (c == 'u')
			|| (c == 'x') || (c == 'X')
			|| (c == '%'));
}

void	jump_nbr(char *s, int *i)
{
	if (s[*i] == '*')
		(*i)++;
	while (ft_isdigit(s[*i]))
		(*i)++;
	return ;
}

int		spclen(char *s)
{
	int		i;

	if (*s != '%')
		return (0);
	i = 1;
	jump_nbr(s, &i);
	while (isflag(s[i]))
		i++;
	jump_nbr(s, &i);
	if (s[i] == '.')
	{
		i++;
		jump_nbr(s, &i);
	}
	if (isconvert(s[i]))
		i++;
	return (i);
}
