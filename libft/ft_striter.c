/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:01:22 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/11 19:49:48 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The ft_striter() function applies the function f to each character of the
** string passed as argument. Each character is passed by address to f to be
** modified if necessary.
*/

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *c))
{
	int	i;

	if (s && f)
	{
		i = 0;
		while (s[i] != '\0')
		{
			f(&s[i]);
			i++;
		}
	}
}
