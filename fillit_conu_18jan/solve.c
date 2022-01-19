/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:10:23 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/19 08:43:06 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//piecelist = struct of all pieces
// map is the struct of the map populated with the dots and letters, modified
// through the function and returned.
// x_offset and y_offset are the offset values for the piece
t_map	*solve(t_piecelist *piecelist, t_map *map, int x_offset, int y_offset)
{
	int		i;
	int		sum;
	t_map	*newmap;

	placepiece(piecelist->list[0], map, x_offset, y_offset);
	i = 1;
	sum = 1;
	while (i < piecelist->count)
	{
		piecelist->list[i]->ingrid = grid_placepiece(piecelist->list[i], map, 0, 0);
		if (piecelist->list[i]->ingrid == 1)
			sum++;
		i++;
		if (sum != i)
		{
			//remove the last piece able to fit on the map and start
			// trying to place it back from one degree offset
			cancelplacepiece(piecelist->list[sum], map, piecelist->list[sum]->topleft_x, piecelist->list[sum]->topleft_y);
			piecelist->list[sum]->ingrid = grid_placepiece(piecelist->list[sum], map, piecelist->list[sum]->topleft_x + 1, piecelist->list[sum]->topleft_y);
			if (piecelist->list[sum]->ingrid == 1)
				sum++;
			else
				newmap = modif_solve_param(piecelist, map, x_offset, y_offset);
				return(newmap);
		}
		else if (sum == i)
			return (map);
	}
	