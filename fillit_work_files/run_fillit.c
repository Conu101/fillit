/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_fillit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:25:37 by ctrouve           #+#    #+#             */
/*   Updated: 2022/02/07 14:50:16 by tburakow         ###   ########.fr       */
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
void	run_fillit(int *coords, int count)
{
	int		map_size;
	t_map	*map;
	t_piece	*list;
	int		ret;

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
	exit(0);
}
