/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:01:59 by tburakow          #+#    #+#             */
/*   Updated: 2021/11/24 13:40:24 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	z;
	size_t			i;
	unsigned char	*d;

	z = (unsigned char)c;
	i = 0;
	d = (unsigned char *)s;
	while (i < n)
	{
		if (d[i] == z)
			return (&d[i]);
		i++;
	}
	return (NULL);
}
