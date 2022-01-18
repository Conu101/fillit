/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:33:19 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/10 17:30:16 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	int		end;

	i = 0;
	end = 0;
	while (i < len)
	{
		if (!src[i])
			end = 1;
		if (!end)
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i++;
	}
	return (dst);
}			
