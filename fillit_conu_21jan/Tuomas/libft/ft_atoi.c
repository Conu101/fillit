/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:43:54 by tburakow          #+#    #+#             */
/*   Updated: 2021/12/16 01:14:11 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_digit(char c)
{
	if ((c > 47 && c < 58))
		return (1);
	else
		return (0);
}

int	is_over_under(long long nbr)
{
	if (nbr > 2147483647)
	{
		if (nbr == 9223372036854775807)
			return (-1);
		else
			return (0);
	}	
	if (nbr < -2147483648)
	{
		if (nbr < -9223372036854775807)
			return (0);
		else
			return (-1);
	}
	return ((int)nbr);
}

static	int	is_space(char c)
{
	if (c == '\n' || c == ' ' || c == '\r')
		return (1);
	if (c == '\v' || c == '\t' || c == '\f')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	n;
	long	a;

	n = 1;
	a = 0;
	while (is_space(*str) == 1)
		str++;
	if (*str == '-')
	{
		n = -1;
		str++;
	}
	if (*str == '+' && (*(str - 1) == '-' || *(str - 1) == '+'))
		return (0);
	if (*str == '+')
		str++;
	if (is_digit(*str) == 0)
		return (0);
	while (is_digit(*str) == 1)
	{
		a = a + *str - '0';
		if (is_digit(*(str++ + 1)) == 1)
			a = a * 10;
	}
	return (is_over_under(a * n));
}
