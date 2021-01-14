/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 12:01:49 by gartaud           #+#    #+#             */
/*   Updated: 2020/11/18 17:06:13 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*my_lstlast(t_list *lst)
{
	t_list *current;

	current = lst;
	while (current->next)
		current = current->next;
	return (current);
}

void			ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!*alst)
		*alst = new;
	else
		my_lstlast(*alst)->next = new;
	new->next = NULL;
	return ;
}
