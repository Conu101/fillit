/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:18:34 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/10 14:13:42 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*p1;
	char	*p2;

	p1 = (char *) s1;
	p2 = (char *) s2;
	while (n > 0)
	{
		if ((unsigned char) *p1 != (unsigned char) *p2)
			return ((unsigned char) *p1 - (unsigned char) *p2);
		p1++;
		p2++;
		n--;
	}
	return (0);
}
