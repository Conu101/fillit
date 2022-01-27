/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fillit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:25:37 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/27 10:44:25 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** checks that the map contains as many letters as 4 times the amount 
** of tetriminos.
*/
int	mapready(t_map *map, int count)
{
	int	i;
	int	j;
	int	full;

	i = 0;
	full = 0;
	while (i < map->map_size)
	{
		j = 0;
		while (j < map->map_size)
		{
			if (map->map_array[i][j] != '.')
				full++;
			j++;
		}
		i++;
	}
	if (full == count * 4)
		return (1);
	else
		return (0);
}

/*
** creates map of minimal size, tries to solve in this map or increases
** map size as many times as necessary. Prints map when ready and frees it.
*/
void	run_fillit(char *str, int count)
{
	int		*coords;
	int		map_size;
	t_map	*map;
	t_piece	*list;
	int		ret;

	coords = ft_strslice(str);
	map_size = get_map_size(count);
	map = makemap(map_size);
	list = makelist(coords, count, 'A');
	solve(list, map, 0, 0);
	ret = mapready(map, count);
	while (ret == 0)
	{
		free_map(map, map_size);
		map_size++;
		map = makemap(map_size);
		solve(list, map, 0, 0);
		ret = mapready(map, count);
	}
	print_map(map, map->map_size);
	free_map(map, map_size);
}
