/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:14:42 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/14 12:52:47 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strsub() function allocates with malloc(3) and returns a "fresh"
** substring from string given as an argument. The substring begins at index
** start and is of size len. If start and len aren't referring to a valid
** substring, the behavior is undefined. If the allocation fails, the function
** returns NULL.
*/

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (s)
	{
		substr = ft_strnew(len);
		if (substr)
		{
			i = start;
			j = 0;
			while (j < len)
			{
				substr[j] = s[i];
				i++;
				j++;
			}
			substr[i] = '\0';
			return (substr);
		}
	}
	return (NULL);
}
