/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:43:28 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/15 14:34:41 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” memory area.
** The memory allocated is initialized to 0. If the allocation fails, the 
** function returns NULL.
** Param. #1 The size of the memory that needs to be allocated.
** Return value The allocated memory area.
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (size)
	{
		ptr = malloc(sizeof(*ptr) * (size));
		if (ptr)
		{
			ft_memset(ptr, 0, size);
			return (ptr);
		}
	}
	return (NULL);
}
