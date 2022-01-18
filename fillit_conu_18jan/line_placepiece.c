/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_placepiece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:10:27 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/18 18:32:50 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	line_placepiece(t_piece *piece, t_map *map, int x_offset, int y_offset)
{
	int	x_var;

	x_var = 0;
	while (x_offset + x_var >= 0 && x_offset + x_var < map->map_size)
	{
		piece->lined = placepiece(piece, map, x_offset + x_var, y_offset);
		if (!piece->lined)
			x_var++;
		piece->topleft_x = x_var;
	}	
	return (piece->lined);
}

//tries to place a piece on the horizontal axis starting from x-offset
// returns 1 if successful or 0 if not