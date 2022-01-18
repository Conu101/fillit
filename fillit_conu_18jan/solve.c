/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:10:23 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/18 15:04:34 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//piecelist = struct of all pieces
// map is the struct of the map populated with the dots and letters
// piece is the piece we want to offset
// x_offset and y_offset are the offset values for the piece
t_map	*solve(t_piecelist *piecelist, t_map *map, t_piece *piece, int x_offset, int y_offset)
{
	int	i;
	int	sum;

	i = 0;
	while (i >= 0 && i < piecelist->count)
	{
		piecelist->list[i]->ingrid = grid_placepiece(piecelist->list[i], map, x_offset, y_offset);
		if (!piecelist->list[i]->ingrid)
		{
			cancelplacepiece(piecelist->list[i - 1], map, x_offset, y_offset);
			x_offset += 1;
			while (x_offset <= map->map_size - 1)
			{
				solve(piecelist, map, x_offset, y_offset);
				if (!piecelist->list[i]->ingrid)
				{
					cancelplacepiece(piecelist->list[i - 1], map, x_offset, y_offset);
					x_offset += 1;
					while (x_offset <= map->map_size - 1)
					{
						solve(piecelist, map, x_offset, y_offset);
					}
		}
		i++;
	}
	//printf("\nbreak 3\n");

// or check afterwards if all pieces were successfuly placed
	sum = 0;
	i = 0;
	while (i < piecelist->count)
	{
		sum = sum + piecelist->list[i++]->placed;
	}
	if (sum != piecelist->count)
	//means that all pieces were not placed -> do something :D
	if (y_offset == map->map_size)
	{
		map->map_size += 1;
	}
	return (map);
}
