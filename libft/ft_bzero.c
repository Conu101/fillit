/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:28:55 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/17 14:35:14 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Library : #include <strings.h>
** The bzero() function writes n zeroed bytes (\0) to the string s.  If n
** is zero, bzero() does nothing.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (n != 0)
	{
		ft_memset(s, '\0', n);
	}
}
