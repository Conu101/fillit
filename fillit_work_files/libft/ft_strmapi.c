/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:06:43 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/09 16:15:31 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The function ft_strmapi() applies the function f to each character of the
** string given as an argument by giving its index as the first argument to
** create a "fresh" new string (with malloc(3)) resulting from the successive
** applications of f.
*/

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int n, char c))
{
	char	*new_str;
	int		i;

	if (s && f)
	{
		new_str = (char *)malloc(sizeof(*new_str) * (ft_strlen((char *)s) + 1));
		if (new_str)
		{
			i = 0;
			while (s[i] != '\0')
			{
				new_str[i] = (*f)(i, s[i]);
				i++;
			}
			new_str[i] = '\0';
			return (new_str);
		}
	}
	return (NULL);
}
