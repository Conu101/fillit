/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:52:11 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/21 19:56:50 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/*int	main(void)
{
	char	**array;
	char	**types;
	int		amount;
	char	*str;
	char 	*tmp;
	int		fd;
	int		ret;
	int		*nbrs;
	int		*coords;
	//char	*single;
	//int		testtype;
	
	
	str = "";
	ret = 8;
	tmp = NULL;
	fd = open("types.txt", O_RDONLY);
	//printf("\n%d\n", fd);
	while (ret != 0)
	{
		ret = get_next_line(fd, &tmp);
		if (ret != 0)
			str = ft_strjoin(str, tmp);
	}
	amount = ft_fill_amount(str);
	types = (char **)malloc(sizeof(char *) * (amount + 1));
	types = ft_fill_split(types, str, ft_strlen(str));
	str = "";
	ret = 8;
	tmp = NULL;
	fd = open("trial.txt", O_RDONLY);
	//printf("\n%d\n", fd);
	while (ret != 0)
	{
		ret = get_next_line(fd, &tmp);
		if (ret != 0)
			str = ft_strjoin(str, tmp);
	}
	amount = ft_fill_amount(str);
	array = (char **)malloc(sizeof(char *) * (amount + 1));
	array = ft_fill_split(array, str, ft_strlen(str));
	//printf("\n%d\n", fd);
	//nbrs = (int *)malloc(sizeof(int) * (amount + 1));
	//printf("\n%d\n", fd);
	nbrs = ft_assign_types(array, types, amount);
	//printf("\n%d\n", fd);
	//printf("\n%d\n", amount);
	//printf("\n%s\n", str);
	//printf("\n%zu\n", ft_strlen(str));
	//ft_print_array(types);
	//printf("\n%d\n", cmp_to_type(types, array[1]));
	//printf("\n%s\n", "From hereon it's the array:");
	//printf("\n%s\n", single);
	//ft_print_array(array);
	//testtype = nbrs[0];
	//print_int_array(nbrs, amount);
	//printf("\n%s\n", "break 1");
	coords = type_to_coords(8);
	print_int_array(coords, 6);
	return (0);
}*/

void	ft_print_int_array(int *arr, int count)
{
	int	i;
	
	i = 0;
	while (i < (count * 8))
	{
		printf("\n%d\n", arr[i]);
		//printf("\n%d\n", i);
		i++;
	}
}

int	main(void)
{
	char	*str;
	//char	**array;
	int		fd;
	int		ret;
	int		*coords;
	t_piece	*list;
	int		count;
	int		map_size;
	t_map	*map;
	//546
	str = (char *)malloc(sizeof(char) * 546);
	fd = open("trialinv.txt", O_RDONLY);
	//546
	ret = read(fd, str, 546);
	str[ret] = '\0';
	count = (ft_strlen(str) / 21);
	if (ft_check_string(str) != 1)
	{
		printf("\n%s\n", "str_check fail.");
		return (0);
	}
	//printf("\n%zu\n", ft_strlen(str));
	coords = ft_strslice(str);
	//printf("\nHere are the coordinates of the array: ly lx (fy fx relatives to leader)*3 ...\n");
	//ft_print_int_array(coords, count);
	//print_int_array(coords, ((ft_strlen(str) / 21) * 8));
	//print_piece_array(list, count);
	//free(str);
	map_size = get_map_size(count);
	//printf("\nThe mapsize from main\n");
	//printf("\n%d\n", map_size);
	map = makemap(map_size);
	//printf("\nThe mapsize from makemap\n");
	//printf("\n%d\n", map->map_size);
	list = makelist(coords, count);
	solve(list, map, 0, 0, count);
	//printf("\nmap after solving original mapsize\n");
	//print_map(map, map->map_size);
	//printf("\n");
	ret = mapready(map, count);
	while (ret == 0)
	{
		free_map(map, map_size);
		map_size++;
		map = makemap(map_size);
		solve(list, map, 0, 0, count);
		ret = mapready(map, count);
	}
	printf("\nmap after increasing mapsize\n");
	print_map(map, map_size);
	printf("\n");
	free_map(map, map_size);
	//print_map(map, map->map_size);
	//map_size = get_map_size(count);
	//printf("\nMap size\n%d\n", map_size);
	//map = ft_mapnew(map_size * map_size);
	//map = check_list(list, map_size);
	//printf("\n%s\n", map);
	return (0);
}
