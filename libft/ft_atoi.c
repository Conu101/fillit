/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:18:48 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/15 13:53:24 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Library : #include <stdlib.h>
** The atoi() function converts the initial portion of the string pointed to 
** by str to int representation, removing any whitespace at the beginning.
*/

#include "libft.h"

static int	ft_if_overlong(int x)
{
	if (x == -1)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	int					neg;
	int					i;
	unsigned long long	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || \
	str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + ((unsigned long long)str[i] - 48);
		i++;
	}
	if (i > 19 || num > 9223372036854775807)
		return (ft_if_overlong(neg));
	return ((int)num * neg);
}
