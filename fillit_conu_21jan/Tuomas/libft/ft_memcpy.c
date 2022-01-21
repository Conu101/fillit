/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 05:36:55 by tburakow          #+#    #+#             */
/*   Updated: 2021/11/26 16:51:52 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*x;
	char		*y;

	i = 0;
	x = (const char *)src;
	y = (char *)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		y[i] = x[i];
		i++;
	}
	return (dst);
}
