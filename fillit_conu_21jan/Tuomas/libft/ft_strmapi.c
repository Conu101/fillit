/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:49:16 by tburakow          #+#    #+#             */
/*   Updated: 2021/11/29 15:48:41 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	i = 0;
	if (!s)
		return (NULL);
	res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	while (i < ft_strlen(s))
	{
		res[i] = f((unsigned int)i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
