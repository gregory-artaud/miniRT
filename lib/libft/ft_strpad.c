/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 08:14:11 by gartaud           #+#    #+#             */
/*   Updated: 2020/12/04 17:52:25 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strpad(char **dest, int side, int min_size, char c)
{
	char	*pad;
	int		pad_ln;
	int		dlen;

	dlen = ft_strlen(*dest);
	pad_ln = min_size - dlen;
	if (pad_ln < 0 || !(pad = ft_calloc(pad_ln + 1, 1)))
		return ;
	if (side == LFT_LEFT)
	{
		ft_memset(pad, c, pad_ln);
		ft_strmcat(&pad, *dest);
		free(*dest);
		*dest = pad;
	}
	else if (side == LFT_RIGHT)
	{
		ft_memset(pad, c, pad_ln);
		ft_strmcat(dest, pad);
		free(pad);
	}
	return ;
}
