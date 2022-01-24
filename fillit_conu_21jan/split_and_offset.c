/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_offset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:12:54 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/21 16:50:15 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


static void	ft_print_int_array(int *arr, int count)
{
	int	i;
	
	i = 0;
	while (i < count * 8)
	{
		printf("\n%d\n", arr[i]);
		//printf("\n%d\n", i);
		i++;
	}
}

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
	printf("\nCut here--------------\n");

						cnt_link[0]++;
				if (str[(jkl[0] - 1) + 1] == '#')
					cnt_link[1]++;
				if (str[(jkl[0] - 1) + 5] == '#')
					cnt_link[1]++;
}*/

static	int	cnt_link_test(size_t *cnt_link_len)
{
	if (cnt_link_len[1] % 3 != 0 && cnt_link_len[0] % 4 != 0 && \
	cnt_link_len[1] % 4 != 0)
		return (0);
	return (1);
}

static int	offset(int **coords, int k, size_t *cnt_link)
{
	//ft_print_int_array(*coords, 1);
	if (cnt_link_test(cnt_link) == 0)
		return (0);
	set_voffset(*coords, (k - 8), *coords[k - 8]);
	//ft_print_int_array(*coords, 1);
	set_hoffset(*coords, (k - 7));
	//ft_print_int_array(*coords, 1);
	set_relative(*coords, (k - 7));
	//ft_print_int_array(*coords, 1);
	//printf("\nHello!!!\n");
	return (1);
}

int	get_map_size(int count)
{
	int	map_size;

	map_size = 2;
	while (map_size * map_size < 4 * count)
		map_size++;
	return (map_size);
}

/*static void	count_and_link(size_t *cnt_link, char **str, size_t j)
{
	cnt_link[0]++;
	if (*str[j + 1] == '#')
		cnt_link[1]++;
	else if (*str[j + 5] == '#')
		cnt_link[1]++;
}*/

int	*split_and_offset(char *str, size_t *jkl, size_t len, int *coords)
{
	size_t	cnt_link[2];

	while (jkl[0] < len)
	{
		cnt_link[0] = 0;
		cnt_link[1] = 0;
		while (jkl[0] % 21 != 0 || jkl[2] == 0)
		{
			jkl[2] = 1;
			if (str[jkl[0]++] == '#')
			{
				cnt_link[0]++;
				if (str[jkl[0] + 1] == '#')
					cnt_link[1]++;
				if (str[jkl[0] + 5] == '#')
					cnt_link[1]++;
				coords[jkl[1]++] = (jkl[0] - 1) % 21 / 5 % 5;
				coords[jkl[1]++] = (jkl[0] - 1) % 21 % 5;
			}
		}
		if (offset(&coords, jkl[1], cnt_link) == 0)
			return (0);
		jkl[2] = 0;
	}
	ft_print_int_array(coords, len / 21);
	return (coords);
}
