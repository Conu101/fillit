/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allblocksinmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:20:00 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/21 11:57:02 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	allblocksinmap(t_piece *piece, t_map *map, int x_offset, int y_offset)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = piece->leader_coord[0];
	x = piece->leader_coord[1];
	if (x + x_offset >= map->map_size || y + y_offset >= map->map_size)
		return (0);
	j = 0;
	i = 1;
	while (j <= 4)
	{
		y = piece->leader_coord[0] + piece->friends_coord[j];
		x = piece->leader_coord[1] + piece->friends_coord[i];
		if (x + x_offset >= map->map_size || y + y_offset >= map->map_size)
			return (0);
		else
		{
			i = i + 2;
			j = j + 2;
		}
	}
	return (1);
}
