/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:04:56 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/18 13:33:58 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Passes the array of types one piece (defined by a type) at a time to the 
** fn makepiece, with the letter assigned to the made piece.
** Returns a linked list of piece structs
*/
t_piece		*makelist(int *coords, int count)
{
	t_piece *current;
	t_piece *first;
	int		i;
	char	letter;
	int		start;
	
	start = 0;
	first = makepiece(coords, 'A', start);
	current = first;
	if (count > 1)
	{
		i = 1;
		letter = 'B';
		while (i < count)
		{
			start += 8;
			current->next = makepiece(coords,letter, start);
			current = current->next;
			letter++;
			i++;
		}
	}
	current->next = NULL;
	return (first);
}
