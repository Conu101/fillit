/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:52:12 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/12 13:18:00 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The function ft_strnew() allocates with malloc(3) and returns a fresh
** string ending with '\0'. Each character of the string is initialized at
** '\0'. If the allocation fails, the function returns NULL.
*/

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (str)
	{
		ft_memset(str, '\0', (size + 1));
		return (str);
	}
	return (NULL);
}
