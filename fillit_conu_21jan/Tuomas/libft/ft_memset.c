/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:09:25 by tburakow          #+#    #+#             */
/*   Updated: 2021/11/29 15:31:00 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	x;
	unsigned char	*f;

	i = 0;
	x = (unsigned char)c;
	f = b;
	while (i < len)
	{
		f[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
