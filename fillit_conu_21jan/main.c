/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:52:11 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/21 15:47:18 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/*static void	ft_print_int_array(int *arr, int count)
{
	int	i;
	
	i = 0;
	while (i < count * 8)
	{
		printf("\n%d\n", arr[i]);
		//printf("\n%d\n", i);
		i++;
	}
}*/

int	create_coords(char *str)
{
	int	*coords;
	size_t len;
	int i;
	size_t jkl[3];
	
	i = 0;
	jkl[0] = 0;
	jkl[1] = 0;
	jkl[2] = 0;
	len = ft_strlen(str);
	coords = (int *)malloc(sizeof(int) * (len / 21) * 8);
	if (split_and_offset(str, jkl, len, coords) == 0)
		return (0);
	//ft_print_int_array(coords, (len / 21) * 8);
	return (1);
}

//int	main(int argc, char **argv)
int main(void)
{
	char	*str;
	int		fd;
	int		ret;
	int		count;

	str = (char *)malloc(sizeof(char) * 546);
	//fd = open(argv[1], O_RDONLY);
	fd = open("trial.txt", O_RDONLY);
	ret = read(fd, str, 546);
	str[ret] = '\0';
	count = (ft_strlen(str) / 21);
	//if (argc != 2)
	//	return (0);
	if (ft_check_string(str) != 1)
	{
		printf("\nnot a valid map file.\n");
		return (0);
	}
	if (create_coords(str) != 1)
	{
		printf("\ncoord creation fail.\n");
		return (0);
	}
	//printf("\nHere comes the string\n");
	//printf("\n%s\n", str);
	//abs_to_rel(coords, 2, coords[0], coords[1]);
	//ft_print_int_array(coords, count);
	//print_piece_array(list, count);
	//free(str);
	//printf("\nThe mapsize from main\n");
	//printf("\n%d\n", map_size);
	//map = makemap(map_size);
	//printf("\nThe mapsize from makemap\n");
	//printf("\n%d\n", map->map_size);
	//list = makelist(coords, count);
	//solve(list, map, 0, 0);
	//print_map(map, map->map_size);
	//map_size = get_map_size(count);
	//printf("\nMap size\n%d\n", map_size);
	//map = ft_mapnew(map_size * map_size);
	//map = check_list(list, map_size);
	//printf("\n%s\n", map);
	return (0);
}
