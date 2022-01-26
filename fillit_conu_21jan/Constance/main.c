/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:52:11 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/26 12:35:43 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	*str;
	int		fd;
	int		ret;
	int		*coords;
	t_piece	*list;
	int		count;
	int		map_size;
	t_map	*map;

	if (argc != 2)
	{
		ft_putstr("usage: enter one filename only after the executable.\n");
			return (1);
	}
	str = (char *)malloc(sizeof(char) * 546);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error: invalid filename.\n");
			return (1);
	}
	ret = read(fd, str, 546);
	str[ret] = '\0';
	count = (ft_strlen(str) / 21);
	if (ft_check_string(str) != 1)
	{
		ft_putstr("error: checkstring failed.\n");
			return (1);
	}
	coords = ft_strslice(str);
	map_size = get_map_size(count);
	map = makemap(map_size);
	list = makelist(coords, count);
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
	return (0);
}
