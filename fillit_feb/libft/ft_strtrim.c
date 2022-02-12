/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:19:02 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/15 14:27:28 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strtrim() function allocates with malloc(3) and returns a copy of
** the string given as argument without whitespaces at the beginning or at
** the end of the string. For this function ' ', '\n' and '\t' are considered 
** whitespace characters. If s has no whitespaces at the beginning or the end,
** the function returns a copy of s. If the allocation fails the function 
** returns NULL.
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		first;
	int		last;
	int		len;

	if (!s)
		return (NULL);
	first = 0;
	while (s[first] != '\0' \
	&& (s[first] == ' ' || s[first] == '\n' || s[first] == '\t'))
		first++;
	last = ft_strlen((char *)s);
	while (first < last && (s[last - 1] == ' ' \
				|| s[last - 1] == '\n' || s[last - 1] == '\t'))
		last--;
	if (first == last)
		return (ft_strnew(1));
	len = last - first;
	return (ft_strsub((char *)s, first, len));
}
