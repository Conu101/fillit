/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:25:06 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/27 10:42:07 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** count is the number of pieces in the file.
** The very minimal map size is the square root of the total number
** of blocks (each piece has 4 blocks so 4 * number of pieces)
*/
int	get_map_size(int count)
{
	int	map_size;

	map_size = 2;
	while (map_size * map_size < 4 * count)
		map_size++;
	return (map_size);
}

/*
** free a map too small and create new map one size bigger.
*/
t_map	*increase_mapsize(t_map *map)
{
	int		new_mapsize;
	t_map	*newmap;

	new_mapsize = map->map_size + 1;
	free_map(map, map->map_size);
	newmap = makemap(new_mapsize);
	if (newmap != NULL)
		return (newmap);
	return (NULL);
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

/*
** free the memory from the map data.
*/
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

/*
** create map of map_size with malloc and populate it 
** entirely with '.'
*/
t_map	*makemap(int map_size)
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
	map->map_size = map_size;
	return (map);
}
