/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makepiece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:58:58 by ctrouve           #+#    #+#             */
/*   Updated: 2022/02/10 17:57:58 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** constructs each piece with malloc and attributes all params of the struct.
*/
t_piece	*makepiece(int *coords, char tetriletter, int start)
{
	t_piece	*piece;
	int		i;

	piece = (t_piece *)malloc(sizeof(t_piece));
	if (!piece)
		return (NULL);
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
	piece->cancel = 0;
	piece->letter = tetriletter;
	return (piece);
}
