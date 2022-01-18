/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:10:23 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/18 20:51:46 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//piecelist = struct of all pieces
// map is the struct of the map populated with the dots and letters, modified
// through the function and returned.
// x_offset and y_offset are the offset values for the piece
t_map	*solve(t_piecelist *piecelist, t_map *map, int x_offset, int y_offset)
{
	int	i;
	int	sum;

	placepiece(piecelist->list[0], map, x_offset, y_offset);
	i = 1;
	sum = 1;
	while (i < piecelist->count)
	{
		piecelist->list[i]->ingrid = grid_placepiece(piecelist->list[i], map, 0, 0);
		if (piecelist->list[i]->ingrid == 1)
			sum++;
		i++;
	}
	if (sum != i) // to do: reset the map
	{
		if (x_offset < map->map_size)
			solve(piecelist, map, x_offset + 1, y_offset);
		else if (x_offset >= map->map_size && y_offset < map->map_size)
			solve(piecelist, map, 0, y_offset + 1);
		else if (y_offset >= map->map_size)
		{
			map->map_size++;
			solve(piecelist, map, 0, 0);
		}
	}
	if (map->map_size > 11)
		return (NULL);
	return (map);
}
