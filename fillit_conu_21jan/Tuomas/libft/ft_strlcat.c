/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:07:41 by tburakow          #+#    #+#             */
/*   Updated: 2021/12/02 11:40:05 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	max;
	size_t	ret_val;

	i = ft_strlen(dst);
	j = 0;
	if (dstsize > i)
		max = (dstsize - i - 1);
	else
		return (ft_strlen(src) + dstsize);
	ret_val = ft_strlen(dst) + ft_strlen(src);
	if (dstsize == 0)
		return (ret_val);
	while (j < max && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ret_val);
}
