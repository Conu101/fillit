/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs_to_rel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:12:05 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/20 11:30:24 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*abs_to_rel(int *coords, int start, int lead_ver, int lead_hor)
{
	int	end;

	end = start + 6;
	while (start < end)
	{
		if (start % 2 == 0)
			coords[start] = coords[start] - lead_ver;
		if (start % 2 != 0)
			coords[start] = coords[start] - lead_hor;
		start++;
	}
	return (coords);
}