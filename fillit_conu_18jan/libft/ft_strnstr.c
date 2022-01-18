/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:33:16 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/11 19:28:02 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strnstr - Find the first substring in a length-limited string
** @hay: The string to be searched in
** @needle: The string to search for
** @len: the maximum number of characters to search
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*s1;
	char	*s2;
	char	*start;
	size_t	i;

	s1 = (char *)haystack;
	if (!(*haystack || *needle))
		return ((char *)haystack);
	while ((*s1 && len > 0) || (len == 0 && *needle == '\0'))
	{
		start = s1;
		s2 = (char *)needle;
		i = len;
		while (*s1 && *s2 && *s1 == *s2 && i > 0)
		{
			s1++;
			s2++;
			i--;
		}
		if (*s2 == '\0')
			return (start);
		len--;
		s1 = start + 1;
	}
	return (NULL);
}
