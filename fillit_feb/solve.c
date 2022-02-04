/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:37:08 by ctrouve           #+#    #+#             */
/*   Updated: 2022/02/04 11:58:53 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** places the first piece at the top left corner of the map annd thn calls 
** itself recursively as long as the current tetrimino does not point to NULL.
** If the return of the function having the next piece as an argument is not 1, 
** shifts the previous piece one place right or down and retries all 
** combinations for following pieces.
*/
int	solve(t_piece *piecelist, t_map *map, int x_offset, int y_offset)
{
	while (y_offset < map->map_size)
	{
		while (x_offset < map->map_size - piecelist->leader_coord[1])
		{
			if (placepiece(piecelist, map, x_offset, y_offset) == 1)
			{
				if (piecelist->next != NULL)
				{
					if (solve(piecelist->next, map, 0, 0) == 1)
						return (1);
					else
					{
						piecelist->cancel = 8;
						cancelplacepiece(piecelist, map, x_offset, y_offset);
					}
				}
				else
					return (1);
			}
			x_offset++;
		}
		x_offset = 0;
		y_offset++;
	}
	return (0);
}
