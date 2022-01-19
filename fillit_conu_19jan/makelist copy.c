/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelist copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:04:56 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/19 18:11:05 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Passes the array of types one piece (defined by a type) at a time to the 
** fn makepiece, with the letter assigned to the made piece.
** Returns a linked list of piece structs
*/
t_piece	*makelist(int *list_coord_array, int count)
{
	t_piece	*first;
	t_piece	*current;
	int		i;
	int		start;
	char	tetriletter;

	i = 0;
	start = 0;
	tetriletter = 'A';
	while (i < count)
	{
		if (tetriletter == 'A')
		{
			first = makepiece(list_coord_array, tetriletter, start);
			current = first;
		}
		else
		{
			start = start + 8;
			current->next = makepiece(list_coord_array, tetriletter, start);
			current = current->next;
		}
		tetriletter++;
		i ++;
	}
	current->next = NULL;
	return (first);
}
