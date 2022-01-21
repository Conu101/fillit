/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shiftpiece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:57:42 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/20 23:00:23 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Shifts a piece 'n' places horizontally
*/

void	shift_x(t_piece *piece, int n)
{
	piece->leader_coord[1] += n;
	piece->friends_coord[1] += n;
	piece->friends_coord[3] += n;
	piece->friends_coord[5] += n;
}

/*
**	Shifts a piece 'n' places vertically
*/

void	shift_y(t_piece *piece, int n)
{
	piece->leader_coord[0] += n;
	piece->friends_coord[0] += n;
	piece->friends_coord[2] += n;
	piece->friends_coord[4] += n;
}