/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:22:33 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/18 15:06:57 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillheader.h"

int	solve_piece(t_piece *list, char **map, int count, int offset)
{
	if (&map[list[count].leader_coords[0] + list[count].leader_coords[1]] + offset == '#')
}

char	*solve_list(t_piece *list, int map_size,int count)
{
	int	i;
	int j;
	//t_piece	temp;
	char	*map;
	
	
	i = 0;
	j = 0;
	map = ft_mapnew(map_size * map_size)
	while (i < ft_recursive_factorial(count))
	{
		if (solve_piece(list, map, count, 0) == 0)
			return (map);
		//swap list objects here
		i++;
	}
	return ("Fail");
}