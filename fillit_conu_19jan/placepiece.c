/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placepiece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:54:22 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/19 14:38:26 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	cancelplacepiece(t_piece *piece, t_map *map, int x_offset, int y_offset)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = piece->leader_coord[0];
	x = piece->leader_coord[1];
	i = 1;
	j = 0;
	while (i <= 4)
	{
		if (map->map_array[x + x_offset][y + y_offset] == piece->letter)
		{
			map->map_array[x + x_offset][y + y_offset] = '.';
			x = x + piece->friends_coord[i];
			y = y + piece->friends_coord[j];
			i = i + 2;
			j = j + 2;
		}
	}
}

int		placepiece(t_piece *piece, t_map *map, int x_offset, int y_offset)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = piece->leader_coord[0];
	x = piece->leader_coord[1];
	if (allblocksinmap(piece, map, x_offset, y_offset) == 0)
		return(0);
	i = 1;
	j = 0;
	while (i <= 4)
	{
		if (map->map_array[x + x_offset][y + y_offset] == '.')
		{
			map->map_array[x + x_offset][y + y_offset] = piece->letter;
			x = x + piece->friends_coord[i];
			y = y + piece->friends_coord[j];
			i = i + 2;
			j = j + 2;
		}
	}
	if (i != 6)
	{
		cancelplacepiece(piece, map, x_offset, y_offset);
		return (0);
	}
	return (1);
}
