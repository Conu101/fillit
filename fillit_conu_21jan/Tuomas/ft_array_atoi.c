/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:58:40 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/17 15:55:07 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillheader.h"

int	*ft_array_atoi(char **array, int type)
{
	int		*coords;
	char	**tmp;
	int		i;

	i = 0;
	coords = (int *)malloc(sizeof(int) * 6);
	tmp = ft_strsplit(array[type], ',');
	while (i < 6)
	{
		//printf("\n%s\n", tmp[i]);
		coords[i] = ft_atoi(tmp[i]);
		i++;
	}
	return (coords);
}