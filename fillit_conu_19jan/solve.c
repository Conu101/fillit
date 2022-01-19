/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:10:23 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/19 17:28:26 by ctrouve          ###   ########.fr       */
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

	placepiece(piecelist->first, map, x_offset, y_offset);
	printf("\nThe rank of first piece\n");
	printf("\n%d\n", piecelist->first->rank);
	i = 1;
	sum = 1;
	print_map(map, map->map_size);
	newmap = NULL;
	while (i < piecelist->tetricount)
	{
		piecelist->current = (t_piece *)malloc(sizeof(t_piece));
		piecelist->current = piecelist->first;
		piecelist->current->next->ingrid = grid_placepiece(piecelist->current->next, map, 0, 0);
		printf("\n%d\n", piecelist->current->next->ingrid);
		if (piecelist->current->ingrid == 1)
			sum++;
		i++;
		piecelist->current = piecelist->current->next;
		if (sum != i)
		{
			//remove the last piece able to fit on the map and start
			// trying to place it back from one degree offset
			cancelplacepiece(piecelist->current, map, piecelist->current->topleft_x, piecelist->current->topleft_y);
			piecelist->current->ingrid = grid_placepiece(piecelist->current, map, piecelist->current->topleft_x + 1, piecelist->current->topleft_y);
			printf("\n%d\n", piecelist->current->ingrid);
			if (piecelist->current->ingrid == 1)
				sum++;
			else
				newmap = modif_solve_param(piecelist, map, x_offset, y_offset);
				return(newmap);
		}
		else if (sum == i)
			return (map);
	}
	return (NULL);
}
