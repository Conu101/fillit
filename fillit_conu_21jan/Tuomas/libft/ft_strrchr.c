/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:24:39 by tburakow          #+#    #+#             */
/*   Updated: 2021/11/29 15:34:13 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	f;
	size_t	i;
	size_t	l;
	int		mark;

	i = 0;
	f = (char)c;
	l = 0;
	mark = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == f)
		{
			l = i;
			mark = 1;
		}
		i++;
	}
	if (mark != 0)
		return ((char *)&s[l]);
	return (NULL);
}
