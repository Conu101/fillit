/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:37:14 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/24 13:26:11 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillheader.h"

int	ft_check_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (0);
		i++;
	}
	return (1);
}
