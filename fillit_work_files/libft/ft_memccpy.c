/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:22:34 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/17 14:49:19 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_memccpy() copies bytes from string src to string dst.  If the character
** c (as converted to an unsigned char) occurs in the string src, the copy
** stops and a pointer to the byte after the copy of c in the string dst
** is returned.  Otherwise, n bytes are copied, and a NULL pointer is returned.
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*access_src;
	unsigned char	*edit_dst;
	unsigned char	character;

	i = 0;
	edit_dst = (unsigned char *)dst;
	access_src = (unsigned char *)src;
	character = (unsigned char)c;
	while (i < n)
	{
		*edit_dst = access_src[i];
		edit_dst++;
		if (character == access_src[i])
		{
			return (edit_dst);
		}
		i++;
	}
	return (NULL);
}
