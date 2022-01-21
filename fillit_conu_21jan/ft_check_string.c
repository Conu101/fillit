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

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (0);
		if (j < 4 && str[i] == '\n')
			return (0);
		if ((i + 1)% 21 == 0 && i != 0 && str[i] != '\n')
			return (0);
		if (str[i] == '\n' && str[i + 2] == '\n')
			return (0);
		i++;
		if ((i + 1) % 21 != 0)
			j++;
		if (j == 3)
			j = 0;	
	}
	return (1);
}
