/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:37:14 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/01 14:47:36 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** check that the tetriminos are comprised of only the allowed symbols, and 
** that the delimiting symbols (newlines) are in the correct position.
*/
int	ft_check_string(char *str)
{
	int	ijk[3];

	ijk[0] = 0;
	ijk[1] = 4;
	ijk[2] = 20;
	while (str[ijk[0]] != '\0')
	{
		if (str[ijk[0]] != '.' && str[ijk[0]] != '#' && str[ijk[0]] != '\n')
			return (0);
		if (ijk[0] == ijk[1])
		{
			if (str[ijk[0]] != '\n')
				return (0);
			ijk[1] += 5;
		}
		if (ijk[0] == ijk[2])
		{
			if (str[ijk[0]] != '\n')
				return (0);
			ijk[1] = ijk[2] + 5;
			ijk[2] += 21;
		}
		ijk[0]++;
	}
	return (1);
}
