/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:16:30 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/15 14:57:46 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The ft_strjoin() function allocates (with malloc(3)) and returns a "fresh"
** string that is the concatenation of s1 and s2, ending with '\0'. If the
** allocation fails, the function returns NULL.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*nstr;
	int		length;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	nstr = (char *)malloc(sizeof(char) * (length + 1));
	if (!nstr)
		return (NULL);
	while (*s1)
		nstr[i++] = *s1++;
	while (*s2)
		nstr[i++] = *s2++;
	nstr[i] = '\0';
	return (nstr);
}
