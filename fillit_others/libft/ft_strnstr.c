/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:46:30 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/12 15:32:45 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	haystack_len;
	size_t	needle_len;
	char	*p_haystack;

	p_haystack = (char *) haystack;
	i = 0;
	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	if (needle_len == 0)
		return (p_haystack);
	else if (needle_len > haystack_len || needle_len > len)
		return (NULL);
	while (i <= haystack_len - needle_len && i <= len - needle_len)
	{
		if (ft_strncmp(&(haystack[i]), needle, needle_len) == 0)
			return (&(p_haystack[i]));
		i++;
	}
	return (NULL);
}
