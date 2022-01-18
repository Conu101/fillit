/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:37:13 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/13 12:24:30 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	place_tetro(t_point start, t_matrix *matrix, t_tetr tetro, t_point point)
{
	int		i;
	int		j;
	t_point	pos;

	i = point.column;
	j = point.row;
	while (j++ < 4)
	{
		while (i < 4)
		{
			if (tetro.grid[j - 1][i] == '#')
			{
				pos.row = start.row + j - 1 - point.row;
				pos.column = start.column + i - point.column;
				matrix->grid[pos.row][pos.column] = tetro.symbol;
			}
			i++;
		}
		i = 0;
	}
	return (1);
}

int	check_tetro(t_point start, t_matrix *matrix, t_tetr tetro)
{
	int		i;
	int		j;
	t_point	pos;

	i = tetro.start.column;
	j = tetro.start.row;
	while (j < 4)
	{
		while (i < 4)
		{
			if (tetro.grid[j][i] == '#')
			{
				pos.row = start.row + j - tetro.start.row;
				pos.column = start.column + i - tetro.start.column;
				if (pos.row < 0 || pos.row >= matrix->size
					|| pos.column < 0 || pos.column >= matrix->size
					|| matrix->grid[pos.row][pos.column] != '.')
					return (0);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (place_tetro(start, matrix, tetro, tetro.start));
}

int	remove_tetro(t_point start, t_matrix *matrix, t_tetr tetro)
{
	int		i;
	int		j;
	t_point	pos;

	i = tetro.start.column;
	j = tetro.start.row;
	while (j < 4)
	{
		while (i < 4)
		{
			if (tetro.grid[j][i] == '#')
			{
				pos.row = start.row + j - tetro.start.row;
				pos.column = start.column + i - tetro.start.column;
				matrix->grid[pos.row][pos.column] = '.';
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}
