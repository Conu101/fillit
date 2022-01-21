/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:42:24 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/04 10:37:42 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	s1l;
	size_t	s2l;

	i = 0;
	j = 0;
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * s1l + s2l + 1);
	if (!res)
		return (NULL);
	while (i < s1l)
		res[j++] = s1[i++];
	i = 0;
	while (i < s2l)
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}
