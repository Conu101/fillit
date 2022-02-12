/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:56:37 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/19 15:50:52 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_memcmp compares two areas of memory.
** s1:	One area of memory
** s2:	Another area of memory
** n:	The size of the area.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*area1;
	const unsigned char	*area2;
	int					result;

	result = 0;
	while (n > 0)
	{
		area1 = (const unsigned char *)s1;
		area2 = (const unsigned char *)s2;
		result = *area1 - *area2;
		if (result != 0)
			break ;
		s1++;
		s2++;
		n--;
	}
	return (result);
}
