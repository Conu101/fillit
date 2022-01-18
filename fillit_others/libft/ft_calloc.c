/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:59:42 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/26 11:07:06 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (!count || !size)
		return (NULL);
	mem = ft_memalloc(count * size);
	if (!mem)
		return (NULL);
	else
		return (mem);
}
