/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:04:56 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/18 22:35:02 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Passes the array of types one piece (defined by a type) at a time to the 
** fn makepiece, with the letter assigned to the made piece.
** Returns a linked list of piece structs
*/
t_piecelist	*makelist(int *types_array, int count)
{
	t_piece *current;
	t_piece *first;
	int		i;
	char	letter;

	first = makepiece(types_array[0], 'A');
	current = first;
	if (count > 1)
	{
		i = 1;
		letter = 'B';
		while (i < count)
		{
			current->next = makepiece(types_array[i],letter);
			current = current->next;
		}
		letter++;
		i++;
	}
	current->next = NULL;
	return (first);
}
