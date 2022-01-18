/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tetrifile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:23:53 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/15 13:57:34 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*makepiece(int **int_array)
{
	t_piece	*piece_pointer;
	int		x;
	int		y;
	int		i;
	char	letter;

	i = 0;
	x = 0;
	y = 1;
	letter = "A";
	if (!(piece_pointer= (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	while (i < 20)
	{
		
		i++;
	}
	piece_pointer->x_pos = 0;
	piece_pointer->y_pos = 0;
	piece_pointer->letter = letter;
	return (piece_pointer);
}

/*
** Passes the buffer to makepiece() one piece-chunk at a time (21 chars)
** Assigns letter to the made piece
** Returns a linked list of piece structs
*/

t_piece		*makelist(char *buf, int size)
{
	t_piece *current;
	t_piece *beginning;
	int		i;
	char	pieceletter;

	i = 0;
	pieceletter = 'A';
	while (i < size)
	{
		if (pieceletter == 'A')
		{
			beginning = makepiece(buf + i, pieceletter);
			current = beginning;
		}
		else
		{
			current->next_piece = makepiece(buf + i, pieceletter);
			current = current->next_piece;
		}
		pieceletter++;
		i += 21;
	}
	current->next_piece = NULL;
	return (beginning);
}
