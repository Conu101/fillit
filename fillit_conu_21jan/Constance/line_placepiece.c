/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_placepiece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:10:27 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/20 14:39:22 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	grid_placepiece(t_piece *piece, t_map *map, int x_offset, int y_offset)
{
	int	x_var;
	int	ret;

	x_var = 0;
	ret = 0;
	while (x_offset + x_var >= 0 && x_offset + x_var < map->map_size)
	{
		ret = placepiece(piece, map, x_offset + x_var, y_offset);
		if (ret == 0)
			x_var++;
	}
	piece->topleft_x = x_var;
	printf("\n%d\n", ret);
	return (ret);
}

//tries to place a piece on the horizontal axis starting from x-offset
// returns 1 if successful or 0 if not