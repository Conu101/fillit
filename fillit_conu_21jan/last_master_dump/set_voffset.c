/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_voffset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:58:49 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/20 22:37:53 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_voffset(int **array, int start, int offset)
{
	int	end;

	end = start + 7;
	while (start < end)
	{
		array[start] = array[start] - offset;
		start += 2;
	}
}
