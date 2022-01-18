/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:29:11 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/10 17:38:09 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
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
	else if (needle_len > haystack_len)
		return (NULL);
	while (i <= haystack_len - needle_len)
	{
		if (ft_strncmp(&(haystack[i]), needle, needle_len) == 0)
			return (&(p_haystack[i]));
		i++;
	}
	return (NULL);
}
