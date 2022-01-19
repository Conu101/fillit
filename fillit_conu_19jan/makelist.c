/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:04:56 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/19 18:03:15 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Passes the array of types one piece (defined by a type) at a time to the 
** fn makepiece, with the letter assigned to the made piece.
** Returns a linked list of piece structs
*/
t_piecelist	*makelist(int *list_coord_array, int count)
{
	t_piecelist	*piecelist;
	int			i;
	int			start;
	char		tetriletter;

	piecelist = (t_piecelist *)malloc(sizeof(t_piecelist));
	if (!piecelist)
		return (NULL);
	piecelist->tetricount = count;
	i = 0;
	start = 0;
	piecelist->first = makepiece(list_coord_array, 'A', start);
	piecelist->current = makepiece(list_coord_array, tetriletter, start);
	if (count > 1)
	{
		piecelist->current = piecelist->first;
		i = 1;
		tetriletter = 'B';
		while (i < count)
		{
			start += 8;
			piecelist->current = makepiece(list_coord_array, tetriletter, start);
			piecelist->current = piecelist->current->next;
			piecelist->current->next = piecelist->current;
			tetriletter++;
			i++;
		}
	}
	piecelist->current->next = NULL;
/*	i = 0;
	while (i < count)
	{
		piecelist->list[i] = list_coord_array[i];
		i++;
	}*/
	return (piecelist);
}
