/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_amount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:10:22 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/14 18:37:34 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillheader.h"

int	ft_fill_amount(char *str)
{
	int	count;
	int nbr;
	int i;
	int	len;
	
	count = 0;
	nbr = 0;
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i])
			nbr++;
		if (nbr % 16 == 0)
			count++;
		i++;
	}
	return (count);
}