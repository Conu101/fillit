/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:42:23 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/12/06 15:40:15 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	d = (char *) dst;
	s = (char *) src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if ((unsigned char) s[i] == (unsigned char) c)
			return (&(d[i + 1]));
		i++;
	}
	return (NULL);
}
