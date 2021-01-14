/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:13:39 by gartaud           #+#    #+#             */
/*   Updated: 2020/12/04 17:52:04 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				checkbase(char *base)
{
	int b_ln;
	int i;
	int j;

	b_ln = ft_strlen(base);
	if (b_ln <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if ((base[i] == '+') || (base[i] == '-') || (base[i] == ' '))
			return (0);
		j = 0;
		while (j < i)
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (1);
}

int				count_digits_base(long long nbr, int base)
{
	int res;

	res = 1;
	while ((nbr /= base))
		res++;
	return (res);
}

char			*ft_itoa_base(long long nbr, char *base)
{
	char	*res;
	int		is_neg;
	int		res_ln;
	int		b_ln;

	if (!base || !checkbase(base))
		return (NULL);
	b_ln = ft_strlen(base);
	res_ln = count_digits_base(nbr, b_ln);
	if ((is_neg = (nbr < 0)))
		res_ln++;
	if (!(res = ft_calloc(res_ln + 1, 1)))
		return (NULL);
	if (is_neg)
		*res = '-';
	res_ln--;
	while (res_ln >= is_neg)
	{
		if (nbr % b_ln < 0)
			nbr *= -1;
		res[res_ln--] = base[nbr % b_ln];
		nbr /= b_ln;
	}
	return (res);
}
