/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:52:46 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/13 14:04:48 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Extra function created for use in ft_strsplit. Based on the value of int 
** skip (1 or 0), it will skip or not the character c and check the next char 
** in the string str.
*/

#include "libft.h"

const char	*ft_find_next_str(const char *str, char c, int skip)
{
	if (skip)
		while (*str != '\0' && *str == c)
			str++;
	else
		while (*str != '\0' && *str != c)
			str++;
	return (str);
}
