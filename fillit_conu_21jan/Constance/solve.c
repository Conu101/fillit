/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 18:37:08 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/23 15:04:17 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

int	solve(t_piece *piecelist, t_map *map, int x_offset, int y_offset, int count)
{

	int	ret;
	int	i;

	//printf("\nmap before solving\n");
	//print_map(map, map->map_size);
	//printf("\n");

	if (!piecelist)
		return (1);
	while (y_offset < map->map_size)
	{
		while (x_offset < map->map_size - piecelist->leader_coord[1])
		{
			ret = placepiece(piecelist, map, x_offset, y_offset);
			if (ret == 1)
			{
				if (piecelist->next != NULL)
				{
					ret = solve(piecelist->next, map, 0, 0, count - 1);
					if ( ret == 1)
						return (1);
					else
						cancelplacepiece(piecelist, map);
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
