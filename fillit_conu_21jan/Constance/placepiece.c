/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placepiece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:54:22 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/21 14:51:45 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

void	cancelplacepiece(t_piece *piece, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_size)
	{
		j = 0;
		while (j < map->map_size)
		{
			if (map->map_array[i][j] == piece->letter)
				map->map_array[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		placepiece(t_piece *piece, t_map *map, int x_offset, int y_offset)
{
	int	x;
	int	y;
	int	i;
	int	j;

	/*printf("\nIf allblocksinmap of piece succeeded: 1, if not: 0");
	printf("\n%d\n", allblocksinmap(piece, map, x_offset, y_offset));*/

	y = piece->leader_coord[0];
	x = piece->leader_coord[1];
	if (allblocksinmap(piece, map, x_offset, y_offset) == 0)
		return(0);
	i = 1;
	j = 0;
	while (j < 7)
	{
		if (map->map_array[y + y_offset][x + x_offset] == '.')
		{
			map->map_array[y + y_offset][x + x_offset] = piece->letter;
			x = piece->leader_coord[1] + piece->friends_coord[i];
			y = piece->leader_coord[0] + piece->friends_coord[j];
			i = i + 2;
			j = j + 2;
		}
//		else if (map->map_array[y + y_offset][x + x_offset] != '.')
//			j = 7;
		else
			break ;
	}
	if (j != 8)
	{
		cancelplacepiece(piece, map);
		return (0);
	}
	piece->topleft_x = x + x_offset - piece->friends_coord[5];
	piece->topleft_y = y + y_offset - piece->friends_coord[4];
	piece->placed = 1;
	return (1);
}
