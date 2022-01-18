/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:34:37 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/12 19:32:31 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_matrix(t_matrix matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!matrix.grid)
	{
		return ;
	}
	while (i < matrix.size)
	{
		j = 0;
		while (j < matrix.size)
		{
			ft_putchar(matrix.grid[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	free_matrix(t_matrix *matrix, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(matrix->grid[i]);
		i++;
	}
	free(matrix->grid);
	free(matrix);
}

void	free_tetriminos_and_exit(t_tetr *tetriminos, int i, int row, int state)
{
	while (i >= 0)
	{
		while (row >= 0)
		{
			free(tetriminos[i].grid[row]);
			row--;
		}
		free(tetriminos[i].grid);
		i--;
		row = 3;
	}
	free(tetriminos);
	exit(state);
}

void	end_game(t_tetr_array *tetriminos, t_matrix *matrix)
{
	print_matrix(*matrix);
	free_matrix(matrix, matrix->size);
	free_tetriminos_and_exit(tetriminos->array, tetriminos->size - 1, 3, 0);
}
