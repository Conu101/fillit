/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:40:54 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/15 14:51:51 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: save a copy of a string (with malloc)
**
** DESCRIPTION:
**		The strdup() function allocates sufficient memory for a copy of the
**	string s1, does the copy, and returns a pointer to it. The pointer may
**	subsequently be used as an argument to the function free(3).
*/

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(*src) * (ft_strlen((char *)src) + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
