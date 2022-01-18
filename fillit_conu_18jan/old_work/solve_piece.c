/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:10:23 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/18 14:42:21 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*solve_piece(t_piece *piece, t_map *map, int x_offset, int y_offset)
{
	
		piece->ingrid = grid_placepiece(piece, map, x_offset, y_offset);
		if (!piece->ingrid)
		{
			cancelplacepiece(piece, map, x_offset, y_offset);
			x_offset += 1;
			while (x_offset <= map->map_size - 1)
			{
				solve(piecelist, map, x_offset, y_offset);
				if (!piecelist->list[i]->ingrid)
			}
		}
		i++;
}
