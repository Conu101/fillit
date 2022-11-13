/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_splits_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:07:56 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/15 14:35:06 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** The ft_count_splits_str() function counts the number of strings existing
** within the string str when the separator character is seps.
*/

#include "libft.h"

int	ft_count_splits_str(const char *str, char seps)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str = ft_find_next_str(str, seps, 1);
		if (*str != '\0')
		{
			i++;
			str = ft_find_next_str(str, seps, 0);
		}
	}
	return (i);
}
