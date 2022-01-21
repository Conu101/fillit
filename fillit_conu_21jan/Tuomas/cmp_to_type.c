/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_to_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:34:23 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/15 12:53:46 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillheader.h"

int	cmp_to_type(char **types, char *single)
{
	int	i;

	i = 0;
	while (types[i] != NULL)
	{
		if (ft_strcmp(single, types[i]) == 0)
		{
			if (i >= 0 && i < 4)
				return (1);
			if (i >= 4 && i < 8)
				return (2);
			if (i >= 8 && i < 14)
				return (3);
			if (i >= 14 && i < 20)
				return (4);
			if (i >= 20 && i < 26)
				return (5);
			if (i >= 26 && i < 32)
				return (6);
			if (i >= 32 && i < 41)
				return (7);
			if (i >= 41 && i < 47)
				return (8);
			if (i >= 47 && i < 53)
				return (9);
			if (i >= 53 && i < 59)
				return (10);
			if (i >= 59 && i < 65)
				return (11);
			if (i >= 65 && i < 71)
				return (12);
			if (i >= 71 && i < 77)
				return (13);
			if (i >= 77 && i < 83)
				return (14);
			if (i >= 83 && i < 89)
				return (15);
			if (i >= 89 && i < 95)
				return (16);
			if (i >= 95 && i < 101)
				return (17);
			if (i >= 101 && i < 107)
				return (18);
			if (i >= 107 && i <= 112)
				return (19);
		}
		i++;
	}
	return(-1);
}
