/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:26:38 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/26 11:36:15 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char const *s)
{
	char	*rev;
	int		size;
	int		i;

	size = (int) ft_strlen(s);
	rev = ft_strnew((size_t) size);
	rev[size] = '\0';
	size--;
	i = 0;
	while (size >= 0)
	{
		rev[size] = s[i];
		i++;
		size--;
	}
	return (rev);
}
