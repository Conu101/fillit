/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapready.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:27:47 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/21 16:31:34 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

int	mapready(t_map *map, int count)
{
	int	i;
	int	j;
	int	full;

	i = 0;
	while (i < map->map_size)
	{
		j = 0;
		while (j < map->map_size)
		{
			if (map->map_array[i][j] != '.')
				full++;
			j++;
		}
		i++;
	}
	if (full == count * 4)
		return (1);
	else
		return (0);
}
