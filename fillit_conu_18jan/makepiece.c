/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makepiece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:58:58 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/17 18:41:00 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*makepiece(int type, char letter)
{
	t_piece	*piece;
	int		leader_coord[2];
	int		friends_coord[6]; //or better name friends_offset ?
	int		i;

	piece = (t_piece *)malloc(sizeof(t_piece));
	if (!piece)
		return (NULL);
	i = 0;
	while (i < 2)
	{
		leader_coord[i] = attrib_leader_coord(type, i);
		piece->leader_coord[i] = leader_coord[i];
		i++;
	}
	i = 0;
	while (i < 6)
	{
		friends_coord[i] = attrib_friends_coord(type, i);
		piece->friends_coord[i] = friends_coord[i];
		i++;
	}
	piece->letter = letter;
	piece->type = type;
	return (piece);
}
