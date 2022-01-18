/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:21:50 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/12 19:47:22 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error_exit(int argc)
{
	if (argc != 2)
	{
		ft_putendl("usage: the number of parameters should be one");
		exit(-1);
	}
}

int	find_size(int amount)
{
	int	size;

	size = 1;
	while (size * size < amount * 4)
	{
		size++;
	}
	return (size);
}

int	main(int argc, char **argv)
{
	int				chars;
	int				file;
	char			buffer[548];
	int				size;
	t_tetr_array	tetrimino;

	error_exit(argc);
	file = open(argv[1], O_RDONLY);
	chars = read(file, buffer, 548);
	if (chars > 547 || chars < 1)
	{
		ft_putendl("error");
		return (-1);
	}
	buffer[chars] = '\0';
	close(file);
	check_input(buffer);
	tetrimino = parse_input(buffer);
	size = find_size(tetrimino.size);
	while (find_best(&tetrimino, size) == 0)
		size++;
	return (0);
}
