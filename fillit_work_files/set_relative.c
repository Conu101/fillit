/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_relative.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:22:20 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/21 16:38:03 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_relative(int *coords, int start)
{
	int	end;
	int	offset;

	end = start + 7;
	offset = coords[start];
	while (start < end)
	{
		coords[start] = coords[start] - offset;
		start += 2;
	}
}
