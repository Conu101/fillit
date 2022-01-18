/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:59:20 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/10 17:30:32 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*new;
	size_t		i;

	new = (char *)malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}
