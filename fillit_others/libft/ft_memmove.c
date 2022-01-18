/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:50:21 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/10 17:28:38 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*p;
	char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	p = (char *) dst;
	s = (char *) src;
	i = 0;
	if (dst > src)
	{
		i = len - 1;
		while (i >= 0)
		{
			p[i] = s[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
