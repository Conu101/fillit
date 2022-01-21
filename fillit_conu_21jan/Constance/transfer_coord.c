/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_coord.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:34:46 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/20 19:02:48 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fillit.h"

/* function to transfor the absolute coordinates in the map into
** leader and friends(relative)
*/
int	*transfer_coord(int *previous)
{
	previous[2] = previous[2] - previous[0];
	previous[3] = previous[3] - previous[1];
	previous[4] = previous[4] - previous[0];
	previous[5] = previous[5] - previous[1];
	previous[6] = previous[6] - previous[0];
	previous[7] = previous[7] - previous[1];
	
	previous[0] = 0;

	if (previous[3] < 0 || previous[5] < 0 || previous[7] < 0)
		previous[1] = 1;
	else
		previous[1] = 0;
	
	return (previous);
}
