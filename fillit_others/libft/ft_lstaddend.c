/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:08:00 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/26 11:19:00 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (*alst != NULL && new != NULL)
	{
		temp = *alst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}
