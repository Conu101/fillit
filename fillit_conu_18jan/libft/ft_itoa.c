/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:29:50 by ctrouve           #+#    #+#             */
/*   Updated: 2021/12/23 10:49:05 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** Allocate (withmalloc(3)) and returns a “fresh” string ending with  '\0'
** representing the integer n given as argument. Negative numbers must be 
** supported. If the allocation fails,the function returns NULL.
*/

#include "libft.h"

static char	*ft_array(char *x, unsigned int number, long int len)
{
	while (number > 0)
	{
		x[len--] = '0' + (number % 10);
		number = number / 10;
	}
	return (x);
}

static long int	ft_len(int n)
{
	long int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*x;
	long int		len;
	unsigned int	number;
	int				sign;

	sign = 1;
	len = ft_len(n);
	x = (char *)malloc(sizeof(char) * (len + 1));
	if (!(x))
		return (NULL);
	x[len--] = '\0';
	if (n == 0)
		x[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		number = n * -1;
		x[0] = '-';
	}
	else
		number = n;
	x = ft_array(x, number, len);
	return (x);
}
