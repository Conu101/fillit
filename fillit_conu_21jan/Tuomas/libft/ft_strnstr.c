/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:14:29 by tburakow          #+#    #+#             */
/*   Updated: 2021/12/02 12:18:10 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(needle) < 1)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		if (ft_strncmp(&haystack[i], needle, ft_strlen(needle)) \
		== 0 && (i + ft_strlen(needle)) <= len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
