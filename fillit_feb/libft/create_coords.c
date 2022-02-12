/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:12:54 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/04 12:46:47 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This function checks that there's a suitable amount of parts per 
** terimino, and that they have the correct amount of links between them.
*/
static	int	cnt_link_test(size_t *cnt_link)
{
	if ((cnt_link[1] % 3 != 0 && cnt_link[1] % 4 != 0) || \
	cnt_link[0] % 4 != 0 || cnt_link[1] == 0)
		return (0);
	return (1);
}

/* 
** This function calls the various offset functions to optimise the 
** position of the tetrimino in the 4 x 4 grid, and change the coordinates
** from absolute to relative (to the top/left hash of the tetrimino.)
*/
static int	offset(int **coords, int k, size_t *cnt_link)
{
	if (cnt_link_test(cnt_link) == 0)
		return (0);
	set_voffset(*coords, (k - 8), (*coords)[k - 8]);
	set_hoffset(*coords, (k - 7));
	set_relative(*coords, (k - 7));
	return (1);
}

/*
** This function splits the input string and converts it to coordinates of
** the tetriminos
*/
int	*split_and_offset(char *str, size_t *ijk, size_t len, int *coords)
{
	size_t	cnt_link[2];

	while (ijk[0] < len)
	{
		cnt_link[0] = 0;
		cnt_link[1] = 0;
		while (ijk[0] % 21 != 0 || ijk[2] == 0)
		{
			ijk[2] = 1;
			if (str[ijk[0]] == '#')
			{
				cnt_link[0]++;
				if (str[ijk[0] + 1] == '#')
					cnt_link[1]++;
				if (str[ijk[0] + 5] == '#')
					cnt_link[1]++;
				coords[ijk[1]++] = (ijk[0]) % 21 / 5 % 5;
				coords[ijk[1]++] = (ijk[0]) % 21 % 5;
			}
			ijk[0]++;
		}
		if (offset(&coords, ijk[1], cnt_link) == 0)
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
