/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:14:48 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/09 15:48:19 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates memory for an array of nmemb objects of size and initializes 
** all bytes in the allocated storage to zero.
*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, (nmemb * size));
	return (mem);
}
