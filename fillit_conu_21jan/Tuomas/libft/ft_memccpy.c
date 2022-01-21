/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:50:07 by tburakow          #+#    #+#             */
/*   Updated: 2021/11/24 13:23:03 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			z;
	size_t					i;
	unsigned char			*d;
	const unsigned char		*s;

	z = (unsigned char)c;
	i = 0;
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == z)
		{
			i++;
			return (&d[i]);
		}
		i++;
	}
	return (NULL);
}
