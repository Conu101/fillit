/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makepiece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:58:58 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/19 16:54:28 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*makepiece(int *coords, char tetriletter, int start)
{
	t_piece	*piece;
	int		i;

	piece = (t_piece *)malloc(sizeof(t_piece));
	if (!piece)
		return (NULL);
	piece->rank = start/8;
	i = 0;
	while (i < 2)
	{
		piece->leader_coord[i] = coords[start];
		i++;
		start++;
	}
	i = 0;
	while (i < 6)
	{
		piece->friends_coord[i] = coords[start];
		i++;
		start++;
	}
	piece->letter = tetriletter;
	piece->topleft_x = 0;
	piece->topleft_y = 0;
	piece->placed = 0;
	piece->lined = 0;
	piece->ingrid = 0;
	piece->next = NULL;
	return (piece);
}
