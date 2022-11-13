/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placepiece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:54:22 by ctrouve           #+#    #+#             */
/*   Updated: 2022/02/07 15:57:56 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** checks that all blocks of the tetrimino are within the bounds of the map
*/
int	allblocksinmap(t_piece *piece, t_map *map, int x_offset, int y_offset)
{
	int	x;
	int	y;
	int	j;

	y = piece->leader_coord[0];
	x = piece->leader_coord[1];
	if (x + x_offset < 0 || y + y_offset < 0 || x + x_offset >= map->map_size \
	|| y + y_offset >= map->map_size)
		return (0);
	j = 0;
	while (j <= 4)
	{
		y = piece->leader_coord[0] + piece->friends_coord[j];
		x = piece->leader_coord[1] + piece->friends_coord[j + 1];
		if (x + x_offset < 0 || y + y_offset < 0 || x + x_offset >= \
		map->map_size || y + y_offset >= map->map_size)
			return (0);
		else
			j = j + 2;
	}
	return (1);
}

/*
** the value of piece->cancel was attributed by the value of the index j in 
** placepiece (between 0 and 6) or set to 8 in run_fillit. 
** Depending on its value we know if only the leader, or one or 2 or 3
** friends were placed on the map and therefore need to be replaced by '.' as 
** we cancel the placement of the piece. 
*/
int	cancelplacepiece(t_piece *piece, t_map *map, int x_offset, int y_offset)
{
	int	y;
	int	x;
	int	i;

	y = piece->leader_coord[0];
	x = piece->leader_coord[1];
	i = 0;
	if (piece->cancel >= 2)
		map->map_array[y + y_offset][x + x_offset] = '.';
	y = piece->leader_coord[0] + piece->friends_coord[i];
	x = piece->leader_coord[1] + piece->friends_coord[i + 1];
	i = i + 2;
	if (piece->cancel >= 4)
		map->map_array[y + y_offset][x + x_offset] = '.';
	y = piece->leader_coord[0] + piece->friends_coord[i];
	x = piece->leader_coord[1] + piece->friends_coord[i + 1];
	i = i + 2;
	if (piece->cancel >= 6)
		map->map_array[y + y_offset][x + x_offset] = '.';
	y = piece->leader_coord[0] + piece->friends_coord[i];
	x = piece->leader_coord[1] + piece->friends_coord[i + 1];
	i = i + 2;
	if (piece->cancel == 8)
		map->map_array[y + y_offset][x + x_offset] = '.';
	return (0);
}

/*
** After verifying that the piece would be entirely within bounds, this 
** function checks that the place of the leader is occupied by a '.' on 
** the map, if yes same for each of the friends. If one of the blocks cannot
** be placed i.e. the place is already occupied by another letter, we call 
** cancelplacepiece to revert the blocks marked with the piece_letter on the 
** map to '.'.
*/
int	placepiece(t_piece *piece, t_map *map, int x_offset, int y_offset)
{
	int	x;
	int	y;
	int	j;

	if (allblocksinmap(piece, map, x_offset, y_offset) == 0)
		return (0);
	y = piece->leader_coord[0];
	x = piece->leader_coord[1];
	j = 0;
	while (j < 7)
	{
		if (map->map_array[y + y_offset][x + x_offset] == '.')
		{
			map->map_array[y + y_offset][x + x_offset] = piece->letter;
			y = piece->leader_coord[0] + piece->friends_coord[j];
			x = piece->leader_coord[1] + piece->friends_coord[j + 1];
			j = j + 2;
		}
		else
			break ;
	}
	piece->cancel = j;
	if (j != 8)
		return (cancelplacepiece(piece, map, x_offset, y_offset));
	return (1);
}
