/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makepiece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:58:58 by ctrouve           #+#    #+#             */
/*   Updated: 2022/02/11 14:28:31 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	piece->letter = tetriletter;
	return (piece);
}
