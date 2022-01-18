/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:01:47 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/10 17:29:44 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	size_t	index;
	char	*p;

	p = (char *)s;
	index = 0;
	len = ft_strlen(p);
	while (index <= len)
	{
		if (p[index] == c)
			return (&(p[index]));
		index++;
	}
	return (NULL);
}
