/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_placepiece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:10:27 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/20 14:39:02 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	line_placepiece(t_piece *piece, t_map *map, int x_offset, int y_offset)
{
	int	y_var;
	int	new_x_offset;
	int	ret;

	y_var = 0;
	ret = 0;
	new_x_offset = x_offset;
	//printf("\n%d\n", map->map_size);
	while (y_offset + y_var >= 0 && y_offset + y_var < map->map_size)
	{
		ret = grid_placepiece(piece, map, new_x_offset, y_offset + y_var);
		if (ret == 0)
		{
			y_var++;
			new_x_offset = 0; // to start from the beginning of the line at next line
		}
		piece->topleft_y = y_var;
	}
	return (ret);
}

//tries to place a piece on the vertical axis starting from y-offset
// and starting from x_offset on the first line, then from x = 0.
// returns 1 if successful or 0 if not