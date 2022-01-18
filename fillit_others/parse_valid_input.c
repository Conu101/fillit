/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_valid_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:32:45 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/13 12:31:03 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point	find_tetropoint(t_tetr tetro)
{
	int		i;
	int		j;
	t_point	tetropoint;

	tetropoint.row = 0;
	tetropoint.column = 0;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tetro.grid[j][i] == '#')
			{
				tetropoint.row = j;
				tetropoint.column = i;
				return (tetropoint);
			}
			i++;
		}
		j++;
	}
	return (tetropoint);
}

int	check_equal(t_point first_p, t_point second_p,
	t_tetr first_t, t_tetr second_t)
{
	int		i;
	int		j;

	i = first_p.column;
	j = first_p.row;
	while (j < 4)
	{
		while (i < 4)
		{
			if (first_t.grid[j][i] == '#' && (second_p.column + i -
				first_p.column >= 4 || second_p.row + j - first_p.row >= 4 ||
				second_t.grid[second_p.row + j -
				first_p.row][second_p.column + i - first_p.column] != '#'))
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

void	find_equal(t_tetr *tetriminos, int index, t_tetr *current)
{
	current->prev = index + 1;
	while (index >= 0)
	{
		if (check_equal(find_tetropoint(*current),
				find_tetropoint(tetriminos[index]), *current,
				tetriminos[index]))
		{
			current->prev = index;
			return ;
		}
		index--;
	}
}

int	copy_tetr(char *buffer, int index, t_tetr *tetriminos, int i)
{
	int	row;
	int	letter;

	row = 0;
	tetriminos[i].grid = (char **)malloc(sizeof(char *) * 4);
	if (!tetriminos[i].grid)
		free_tetriminos_and_exit(tetriminos, i - 1, 3, -1);
	while (row < 4)
	{
		tetriminos[i].grid[row] = (char *)malloc(sizeof(char) * 5);
		if (!tetriminos[i].grid[row])
			free_tetriminos_and_exit(tetriminos, i, row - 1, -1);
		letter = 0;
		while (letter < 4)
		{
			tetriminos[i].grid[row][letter] = buffer[index];
			index++;
			letter++;
		}
		index++;
		row++;
	}
	tetriminos[i].symbol = 'A' + i;
	tetriminos[i].start = find_tetropoint(tetriminos[i]);
	return (index);
}

t_tetr_array	parse_input(char *buffer)
{
	t_tetr			*tetriminos;
	t_tetr_array	array;
	int				i;
	int				index;
	int				amount;

	i = 0;
	index = 0;
	amount = (ft_strlen(buffer) + 1) / 21;
	tetriminos = (t_tetr *)malloc(sizeof(t_tetr) * amount + 1);
	if (!tetriminos)
		exit(-1);
	while (i < amount)
	{
		index = copy_tetr(buffer, index, tetriminos, i) + 1;
		find_equal(tetriminos, i - 1, &tetriminos[i]);
		i++;
	}
	array.array = tetriminos;
	array.size = amount;
	return (array);
}
