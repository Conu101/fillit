/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_mapsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:59:30 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/21 19:26:50 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*increase_mapsize(t_map *map)
{
	int		new_mapsize;
	t_map	*newmap;

	if (map->map_size > 11)
	{
		ft_putstr("Error : mapsize > 11");
		return (NULL);
	}
	else
	{
		new_mapsize = map->map_size + 1;
		free_map(map, map->map_size);
		newmap = makemap(new_mapsize);
		return (newmap);
	}
}
