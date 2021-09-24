/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:13:06 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/04/17 15:56:01 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*last;

	if (!lst || !f)
		return (NULL);
	aux = ft_lstnew(f(lst->content));
	last = aux;
	while (lst->next)
	{
		lst = lst->next;
		aux->next = ft_lstnew(f(lst->content));
		if (!(aux->next))
		{
			ft_lstclear(&aux, del);
			return (NULL);
		}
		aux = aux->next;
	}
	return (last);
}
