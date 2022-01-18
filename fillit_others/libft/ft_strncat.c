/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:54:22 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/10 14:34:50 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	len;

	len = ft_strlen(s2);
	i = 0;
	while (s1[i])
		i++;
	if (len > n)
		len = n;
	ft_strncpy(&(s1[i]), s2, len);
	s1[i + len] = '\0';
	return (s1);
}
