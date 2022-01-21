/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:26:12 by tburakow          #+#    #+#             */
/*   Updated: 2021/12/07 14:31:20 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_array(char **array, size_t wc)
{
	size_t	i;

	i = 0;
	while (i < wc)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}
