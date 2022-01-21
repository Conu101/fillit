/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:33:32 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/09 15:55:23 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putendl() function outputs a string to the standard output, followed
** by a newline.
*/

#include "libft.h"

void	ft_putendl(char const *s)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
		ft_putchar('\n');
	}
}
