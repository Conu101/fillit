/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makepiece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:58:58 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/18 13:29:58 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*makepiece(int *coords, char letter,int start)
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
		leader_coord[i] = coords[start];
		piece->leader_coord[i] = leader_coord[i];
		i++;
		start++;
	}
	i = 0;
	while (i < 6)
	{
		friends_coord[i] = coords[start];
		piece->friends_coord[i] = friends_coord[i];
		i++;
		start++;
	}
	piece->letter = letter;
	return (piece);
}
