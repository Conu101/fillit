/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:12:54 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/10 19:00:26 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This function checks that there's a suitable amount of parts per 
** terimino, and that they have the correct amount of links between them.
*/
static int	cnt_link_tet_test(size_t *cnt_link_tet)
{
	if ((cnt_link_tet[1] % 3 != 0 && cnt_link_tet[1] % 4 != 0) || \
	cnt_link_tet[0] % 4 != 0 || cnt_link_tet[1] == 0)
		return (0);
	return (1);
}

/* 
** This function calls the various offset functions to optimise the 
** position of the tetrimino in the 4 x 4 grid, and change the coordinates
** from absolute to relative (to the top/left hash of the tetrimino.)
*/
static int	offset(int **coords, int k, size_t *cnt_link_tet)
{
	if (cnt_link_tet_test(cnt_link_tet) == 0)
		return (0);
	set_voffset(*coords, (k - 8), (*coords)[k - 8]);
	set_hoffset(*coords, (k - 7));
	set_relative(*coords, (k - 7));
	return (1);
}

static void	count_and_link(size_t *cnt_link_tet, char *str, size_t i)
{
	cnt_link_tet[0]++;
	if (str[i + 1] == '#')
		cnt_link_tet[1]++;
	if (str[i + 5] == '#' && (i + 5) < cnt_link_tet[2])
		cnt_link_tet[1]++;
}

/*
** This function splits the input string and converts it to coordinates of
** the tetriminos
*/
int	*split_and_offset(char *str, size_t *ijk, size_t len, int *coords)
{
	size_t	cnt_link_tet[3];

	while (ijk[0] < len)
	{
		cnt_link_tet[0] = 0;
		cnt_link_tet[1] = 0;
		cnt_link_tet[2] = ijk[0] + 21;
		while (ijk[0] % 21 != 0 || ijk[2] == 0)
		{
			ijk[2] = 1;
			if (str[ijk[0]] == '#')
			{
				count_and_link(cnt_link_tet, str, ijk[0]);
				coords[ijk[1]++] = (ijk[0]) % 21 / 5 % 5;
				coords[ijk[1]++] = (ijk[0]) % 21 % 5;
			}
			ijk[0]++;
		}
		if (offset(&coords, ijk[1], cnt_link_tet) == 0)
			return (NULL);
		ijk[2] = 0;
	}
	return (coords);
}

/*
** Creates the coordinate array and other required variables.
*/
int	*create_coords(char *str)
{
	int		*coords;
	size_t	len;
	size_t	ijk[3];

	ijk[0] = 0;
	ijk[1] = 0;
	ijk[2] = 0;
	len = ft_strlen(str);
	coords = (int *)malloc(sizeof(int) * ((len + 1) / 21) * 8);
	if (split_and_offset(str, ijk, len, coords) == NULL)
		return (NULL);
	free(str);
	str = NULL;
	return (coords);
}
