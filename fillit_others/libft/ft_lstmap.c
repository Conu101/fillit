/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:47:39 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/18 16:48:57 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	new = f(lst);
	if (new == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (new);
	if (lst->next != NULL)
	{
		new->next = ft_lstmap(lst->next, f);
		if (new->next == NULL)
		{
			free(new);
			return (NULL);
		}
	}
	return (new);
}
