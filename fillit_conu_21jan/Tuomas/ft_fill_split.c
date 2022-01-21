/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:40:16 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/14 20:01:45 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillheader.h"

char	**ft_fill_split(char **arr, char *str, int len)
{
	int		i;
	int		j;
	int		k;
	int		nbr;

	i = 0;
	j = 0;
	k = 0;
	while (i < len)
	{
		j = 0;
		nbr = 3;
		arr[k] = (char *)malloc(sizeof(char) * 17);
		while (nbr % 16 != 0)
		{
			arr[k][j] = str[i];
			i++;
			j++;
			nbr = i;
		}
		arr[k][j] = '\0';
		k++;
	}
	return (arr);
}
