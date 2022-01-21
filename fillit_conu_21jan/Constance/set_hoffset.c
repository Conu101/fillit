/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hoffset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:06:51 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/19 12:19:32 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*set_hoffset(int *array, int start)
{
	int	end;
	int	last;
	int	offset;
	int	orig;

	end = start + 7;
	offset = 0;
	orig = start;
	last = 100;
	while (start < end)
	{
		if (array[start] != 0 && array[start] < last)
			offset = array[start];
		last = offset;
		start += 2;
	}
	while (orig < start)
	{
		array[orig] = array[orig] - offset;
		orig += 2;
	}
	return (array);
}
