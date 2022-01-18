/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_solve_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:59:30 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/18 22:18:19 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	modif_solve_param(t_piecelist *piecelist, t_map *map, int x_offset, int y_offset)
{
	int		new_mapsize;
	t_map	*newmap;

	if (x_offset < map->map_size - 1)
	{
		reset_map(map, map->map_size); // to do: reset the map to all '.'
		solve(piecelist, map, x_offset + 1, y_offset);
	}
	else if (x_offset >= map->map_size - 1 && y_offset < map->map_size - 1)
	{
		reset_map(map, map->map_size);
		solve(piecelist, map, 0, y_offset + 1);
	}
	else if (y_offset >= map->map_size - 1)
	{
		new_mapsize = map->map_size + 1;
		free_map(map, map->map_size);
		newmap = makemap(new_mapsize);
		solve(piecelist, newmap, 0, 0);
	}
	if (map->map_size > 11)
		ft_putstr("Error : mapsize > 11");
}
