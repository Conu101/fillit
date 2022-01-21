/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:04:59 by tburakow          #+#    #+#             */
/*   Updated: 2021/11/30 12:57:54 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*new;

	if (!lst)
		return (NULL);
	temp = ft_lstnew(f(lst)->content, f(lst)->content_size);
	new = temp;
	if (!new)
		return (NULL);
	while (lst->next != NULL)
	{
		temp->next = ft_lstnew(f(lst->next)->content, \
		f(lst->next)->content_size);
		if (!temp->next)
			ft_lstdel(&new, &ft_bzero);
		lst = lst->next;
		temp = temp->next;
	}
	return (new);
}
