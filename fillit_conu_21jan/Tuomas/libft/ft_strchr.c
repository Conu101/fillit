/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:24:39 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/04 10:07:01 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	f;
	size_t	i;
	size_t	j;

	i = 0;
	f = (char)c;
	j = ft_strlen(s);
	while (i <= j)
	{
		if (s[i] == f)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
