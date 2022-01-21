/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:55:10 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/09 18:12:17 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: locate a substring in a string
**
** DESCRIPTION:
** 		The strstr() function locates the first occurrence of the null-
**	terminated string s2 in the null-terminated string s1.
*/

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*phaystack;
	int		needle_len;

	phaystack = (char *)haystack;
	needle_len = ft_strlen((char *)needle);
	if (needle_len == 0)
	{
		return (phaystack);
	}
	while (*phaystack)
	{
		if (*phaystack == *needle)
		{
			if (ft_strncmp(needle, phaystack, needle_len) == 0)
			{
				return (phaystack);
			}
		}
		phaystack++;
	}
	return (NULL);
}
