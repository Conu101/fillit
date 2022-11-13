/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:09:20 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/17 14:49:26 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The ft_strequ() function does a lexicographical comparison between s1 and
** s2. If the 2 strings are identical the function returns 1, or 0 otherwise.
*/

#include "libft.h"

int	ft_strequ(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	if (s1 && s2)
	{
		while ((*s1 && *s2) && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (!(*s1 - *s2))
			return (1);
	}
	return (0);
}
