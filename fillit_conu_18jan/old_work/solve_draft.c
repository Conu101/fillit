/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:10:23 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/18 13:36:59 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*solve(t_piecelist *piecelist, t_map *map)
{
	int		x_offset[26];
	int		y_offset[26];
	int		i;
	int		sum;

	i = 0;
	while (i >= 0 && i < piecelist->count)
	{
		y_offset[i] = 0;
		while (y_offset[i] >= 0 && y_offset[i] < map->map_size)
		{
			x_offset[i] = 0;
			while (x_offset[i] >= 0 && x_offset[i] < map->map_size)
			{
				piecelist->placed[i] = placepiece(piecelist->list[i], map, x_offset[i], y_offset[i]);
				if (!piecelist->placed[i])
					x_offset[i]++;
			}
			piecelist->placed[i] = placepiece(piecelist->list[i], map, x_offset[i], y_offset[i]);
			if (!piecelist->placed[i])
				y_offset[i]++;
		}
		//printf("\nbreak 2\n");
		//if y_offset incremented beyond map_size (so the whole grid was tried and the piece did not fit)
		//-> we want to move the previous piece one posiion further and retry the next piece.
		if(y_offset[i] == map->map_size)
		{
			cancelplacepiece(piecelist->list[i-1], map, x_offset[i-1], y_offset[i-1]);
			placepiece(piecelist->list[i-1], map, x_offset[i-1] + 1, y_offset[i-1]);
			
			
		}
		
		i++;
	}
	//printf("\nbreak 3\n");

// or check afterwards if all pieces were successfuly placed
	sum = 0;
	i = 0;
	while (i < piecelist->count)
	{
		sum = sum + piecelist->placed[i++];
	}
	if (sum != piecelist->count)
	//means that all pieces were not placed -> do something :D
	if (y_offset == map->map_size)
	{
		map->map_size += 1;
	}
	return (map);
}
