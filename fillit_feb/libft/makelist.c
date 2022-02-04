/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:04:56 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/27 09:58:03 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Passes the array of types one piece (defined by a type) at a time to the 
** fn makepiece, with the letter assigned to the made piece.
** Returns a linked list of piece structs
*/
t_piece	*makelist(int *list_coord_array, int count, char letter)
{
	t_piece	*first;
	t_piece	*current;
	int		i;
	int		start;

	i = 0;
	start = 0;
	while (i++ < count)
	{
		if (letter == 'A')
		{
			first = makepiece(list_coord_array, letter, start);
			current = (t_piece *)malloc(sizeof(t_piece));
			current = first;
		}
		else
		{
			start = start + 8;
			current->next = makepiece(list_coord_array, letter, start);
			current = current->next;
		}
		letter++;
	}
	current->next = NULL;
	return (first);
}
