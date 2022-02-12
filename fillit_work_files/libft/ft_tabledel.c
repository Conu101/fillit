/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabledel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:17:53 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/13 13:21:21 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The ft_tabledel() function is used to free the memory allocated to a whole
**  array of strings array [x] with x < i.
*/

#include "libft.h"

void	*ft_tabledel(char **array, int i)
{
	int	x;

	x = 0;
	if (array)
	{
		while (x < i)
		{
			free(array[x]);
			x++;
		}
		free(array);
	}
	return (NULL);
}
