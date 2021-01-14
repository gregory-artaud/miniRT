/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartaud <gartaud@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 12:05:42 by gartaud           #+#    #+#             */
/*   Updated: 2020/11/18 17:05:27 by gartaud          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		my_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *next;
	t_list *current;

	current = *lst;
	while (current)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
	return ;
}

static t_list	*my_lstnew(void *content)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	new->content = content;
	new->next = NULL;
	return (new);
}

static t_list	*my_lstlast(t_list *lst)
{
	t_list *current;

	current = lst;
	while (current->next)
		current = current->next;
	return (current);
}

static void		my_lstadd_back(t_list **alst, t_list *new)
{
	if (!*alst)
		*alst = new;
	else
		my_lstlast(*alst)->next = new;
	new->next = NULL;
	return ;
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;
	t_list *new_elem;

	if (!lst || !f)
		return (NULL);
	if (!(new_elem = my_lstnew(f(lst->content))))
	{
		my_lstclear(&lst, del);
		return (NULL);
	}
	new_list = new_elem;
	lst = lst->next;
	while (lst)
	{
		if (!(new_elem = my_lstnew(f(lst->content))))
		{
			my_lstclear(&lst, del);
			my_lstclear(&new_list, del);
			break ;
		}
		my_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}
