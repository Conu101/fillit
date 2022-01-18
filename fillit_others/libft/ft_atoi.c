/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:48:02 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/10 17:52:17 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	trim_spaces(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\f'))
		i++;
	return (i);
}

static	int	overflow(int sign)
{
	long	max;
	long	min;

	max = (2 >> 31) - 1;
	min = (-2 >> 31) + 1;
	if (sign > 0)
		return ((int) max);
	else
		return ((int) min);
}

int	ft_atoi(char const *str)
{
	int		index;
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	index = trim_spaces(str);
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (ft_isdigit(str[index]))
	{
		result = result * 10 + (str[index] - '0');
		if (result < 0)
			return (overflow(sign));
		index++;
	}
	result = result * sign;
	return ((int) result);
}
