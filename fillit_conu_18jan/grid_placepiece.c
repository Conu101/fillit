/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_placepiece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:10:27 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/18 21:56:07 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	grid_placepiece(t_piece *piece, t_map *map, int x_offset, int y_offset)
{
	int	y_var;

	y_var = 0;
	while (y_offset + y_var >= 0 && y_offset + y_var < map->map_size)
	{
		piece->ingrid = line_placepiece(piece, map, x_offset, y_offset + y_var);
		if (!piece->ingrid)
		{
			y_var++;
			x_offset = 0; // to start from the beginning of the line at next line
		}
		piece->topleft_y = y_var;
	}
	return (piece->ingrid);
}

//tries to place a piece on the vertical axis starting from y-offset
// and starting from x_offset on the first line, then from x = 0.
// returns 1 if successful or 0 if not