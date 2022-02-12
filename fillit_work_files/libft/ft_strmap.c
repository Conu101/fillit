/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:04:44 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/09 16:14:03 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The function ft_strmap() applies the function f to each character of the
** string given as an argument to create a "fresh" new string (with malloc(3))
** resulting from the successive applications of f.
*/

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char c))
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
				new_str[i] = (*f)(s[i]);
				i++;
			}
			new_str[i] = '\0';
			return (new_str);
		}
	}
	return (NULL);
}
