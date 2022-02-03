/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:37:14 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/21 12:55:09 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_string(char *str)
{
	int	i;
	int j;
	int k;

	i = 0;
	j = 4;
	k = 20;
	if ((ft_strlen(str) + 1) % 21 != 0)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		if (i == j)
		{
			if (str[i] != '\n')
				return (0);
			j += 5;
		}
		if (i == k)
		{
			if (str[i] != '\n')
				return (0);
			j = k + 5;
			k += 21;
		}
		i++;
	}
	return (1);
}
