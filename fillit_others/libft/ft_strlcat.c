/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:20:25 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/10 15:18:23 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	space;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = dst_len;
	if (dst_len >= dstsize)
		dst_len = dstsize;
	if ((int) i < (int) dstsize - 1)
	{
		space = dstsize - i - 1;
		if (src_len > space)
		{
			ft_strncpy(&(dst[i]), src, space);
			i = i + space;
			dst[i] = '\0';
		}
		else
			ft_strcpy(&(dst[i]), src);
	}
	return (dst_len + src_len);
}
