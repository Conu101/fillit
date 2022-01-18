/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:07:38 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/10 17:31:31 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*p;

	p = (char *) s;
	len = (int) ft_strlen(p);
	while (len >= 0)
	{
		if ((unsigned char) p[len] == (unsigned char) c)
			return (&(p[len]));
		len--;
	}
	return (NULL);
}
