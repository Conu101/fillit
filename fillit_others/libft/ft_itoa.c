/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:38:46 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/10 17:28:08 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_digits(long ln)
{
	int	digits;

	digits = 1;
	if (ln < 0)
	{
		digits++;
		ln = -ln;
	}
	while (ln >= 10)
	{
		digits++;
		ln = ln / 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	ln;

	ln = n;
	i = count_digits(ln);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	if (ln < 0)
	{
		str[0] = '-';
		ln = -ln;
	}
	while (ln >= 10)
	{	
		str[i - 1] = '0' + (ln % 10);
		i--;
		ln = ln / 10;
	}
	str[i - 1] = '0' + ln;
	return (str);
}
