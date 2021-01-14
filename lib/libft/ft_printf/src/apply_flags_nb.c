/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 17:21:05 by gartaud           #+#    #+#             */
/*   Updated: 2020/12/04 17:50:26 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	insert_minus(char **dest)
{
	int		i;

	i = 0;
	if (ft_strchr(*dest, '-'))
		return ;
	while ((*dest)[i] == ' ')
		i++;
	if (!i)
		ft_strpad(dest, LFT_LEFT, ft_strlen(*dest) + 1, '-');
	else
		ft_strinsert(dest, i, '-');
	return ;
}

void	apply_flags_nb(char **dest, t_print *p, int spc_i, int is_neg)
{
	int		flag;
	int		nb_ln;

	flag = get_flag(p, spc_i);
	nb_ln = ft_strlen(*dest);
	if (nb_ln < p->precision)
		ft_strpad(dest, LFT_LEFT, p->precision, '0');
	if (nb_ln < p->min_width)
	{
		if (flag == '-')
			ft_strpad(dest, LFT_RIGHT, p->min_width - is_neg, ' ');
		else if (flag == '0')
			ft_strpad(dest, LFT_LEFT, p->min_width - is_neg, '0');
		else
			ft_strpad(dest, LFT_LEFT, p->min_width - is_neg, ' ');
	}
	return ;
}
