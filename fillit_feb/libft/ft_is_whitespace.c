/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:30:50 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/15 15:43:49 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** Bonus function that returns 1 if the character in question is a whitespace.
*/

#include "libft.h"

int	ft_is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == ' ' || c == '\v' || c == '\r' \
	|| c == '\f')
		return (1);
	else
		return (0);
}
