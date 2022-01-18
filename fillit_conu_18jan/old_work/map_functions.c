/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:55:57 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/15 13:06:05 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	find_mapsize(int count)
{
	int	map_size;

	map_size = 2;
	while (map_size * map_size < count)
		map_size++;
	return (map_size);
}

t_map	*create_map(int map_size)
{
	t_map	*map;
	int		i;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->map_array = (char **)ft_memalloc(sizeof(char *) * map_size);
	i = 0;
	while (i < map_size)
	{
		map->map_array[i] = ft_strnew(map_size);
		ft_memset(map->map_array[i], '.', map_size);
		i++;
	}
	return (map);
}

/*
** Print the map one row at a time followed by newline.
*/

void	print_map(t_map *map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map->map_array[i]);
		ft_putchar('\n');
		i++;
	}
}

void	free_map(t_map *map, int map_size)
{
	int	i;

	i = 0;
	while (i < map_size)
	{
		ft_memdel((void **)&(map->map_array[i]));
		i++;
	}
	ft_memdel((void **)&(map->map_array));
	ft_memdel((void **)&map);
}
