/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:19:14 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/18 13:47:37 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	if (lst != NULL)
	{
		while (lst != NULL)
		{
			ft_putstr(lst->content);
			ft_putchar('\n');
			lst = lst->next;
		}
	}
}
