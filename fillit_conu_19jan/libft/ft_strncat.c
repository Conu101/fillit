/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:06:31 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/11 19:31:43 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <string.h>
** SYNOPSIS: concatenate strings (s2 into s1, size-bounded)
**
** DESCRIPTION:
** 		The strcat() and strncat() functions append a copy of the null-
**	terminated string s2 to the end of the null-terminated string s1, then
**	add a terminating '\0'.  The string s1 must have sufficient space to hold
**	the result.
** 		The strncat() function appends not more than n characters from s2, and
**	then adds a terminating '\0'.
*/

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (s2[j] != '\0' && j < (int)n)
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
