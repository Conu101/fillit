/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:11:26 by ctrouve           #+#    #+#             */
/*   Updated: 2021/11/29 11:04:50 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The ft_strnequ() function does a lexicographical comparison between s1 and
** s2. If the 2 strings are identical the function returns 1, or 0 otherwise.
*/

#include "libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (s1 && s2)
	{
		if (ft_strncmp(s1, s2, n) == 0)
		{
			return (1);
		}
	}
	return (0);
}
