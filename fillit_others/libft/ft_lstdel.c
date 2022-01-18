/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:38:35 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/18 16:41:51 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;

	while (*alst != NULL)
	{
		lst = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = lst;
	}
	*alst = NULL;
}
