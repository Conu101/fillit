/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:37:45 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/10 12:20:32 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*p;
	char	*s;

	if (dst == NULL && src == NULL)
		return (0);
	p = (char *) dst;
	s = (char *) src;
	i = 0;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	return (dst);
}
