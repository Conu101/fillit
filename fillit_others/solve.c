/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:20:15 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/13 12:22:10 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	find_start_coordinate(t_matrix *m, t_tetr_array *tetros,
	int index, t_point *s)
{
	int		i;
	int		j;

	i = 0;
	while (i < m->size)
	{
		j = 0;
		while (j < m->size)
		{
			if (m->grid[i][j] ==
				tetros->array[tetros->array[index].prev].symbol)
			{
				s->row = i;
				s->column = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	put_tetrimino(t_tetr_array *tetros,
	t_matrix *matrix, int size, int index)
{
	t_point	next;

	if (index == tetros->size)
		end_game(tetros, matrix);
	next.row = 0;
	next.column = 0;
	if (tetros->array[index].prev != index)
		find_start_coordinate(matrix, tetros, index, &next);
	while (next.row < matrix->size)
	{
		while (next.column < matrix->size)
		{
			if (matrix->grid[next.row][next.column] == '.')
			{
				if (check_tetro(next, matrix, tetros->array[index]) == 1)
				{
					put_tetrimino(tetros, matrix, size, index + 1);
					remove_tetro(next, matrix, tetros->array[index]);
				}
			}
			next.column++;
		}
		next.column = 0;
		next.row++;
	}
}

int	create_matrix(t_matrix *matrix, int size, int i, int j)
{
	matrix->grid = (char **)malloc(sizeof(char *) * size);
	if (!matrix->grid)
	{
		free(matrix);
		return (-1);
	}
	while (i < size)
	{
		j = 0;
		matrix->grid[i] = (char *)malloc(sizeof(char) * size);
		if (!matrix->grid[i])
		{
			free_matrix(matrix, i);
			return (-1);
		}
		while (j < size)
		{
			matrix->grid[i][j] = '.';
			j++;
		}
		i++;
	}
	return (1);
}

int	find_best(t_tetr_array *tetriminos, int size)
{
	t_matrix	*new;

	new = (t_matrix *)malloc(sizeof(t_matrix));
	if (!new || create_matrix(new, size, 0, 0) == -1)
		free_tetriminos_and_exit(tetriminos->array,
			tetriminos->size - 1, 3, -1);
	new->size = size;
	put_tetrimino(tetriminos, new, size, 0);
	free_matrix(new, new->size);
	return (0);
}
