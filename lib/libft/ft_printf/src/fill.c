/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:54:23 by gartaud           #+#    #+#             */
/*   Updated: 2021/01/14 13:44:27 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Puts in s1 the rest of s2 untill the next '%'
** character or the end of s2 and
** returns the size of this chunk
*/

int		fill(t_print *p, int *i)
{
	char	*sub;
	char	*tmp;
	char	*rd_head;
	int		sub_ln;

	rd_head = p->format + *i;
	if ((tmp = ft_strchr(rd_head, '%')))
		sub_ln = tmp - rd_head;
	else
		sub_ln = ft_strlen(rd_head);
	if (!sub_ln)
		return (0);
	sub = ft_substr(rd_head, 0, sub_ln);
	if (write(STDOUT_FILENO, sub, sub_ln) == -1)
		return (0);
	*i += sub_ln - 1;
	free(sub);
	return (sub_ln);
}
