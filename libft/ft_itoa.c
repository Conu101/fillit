/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:29:50 by ctrouve           #+#    #+#             */
/*   Updated: 2022/11/13 12:02:00 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
** Allocate (withmalloc(3)) and returns a “fresh” string ending with  '\0'
** representing the integer n given as argument. Negative numbers must be 
** supported. If the allocation fails,the function returns NULL.
*/

#include "libft.h"

static size_t	get_length(int n)
{
	if (n / 10 == 0)
		return (1 + (n < 0));
	return (1 + get_length(n / 10));
}

static void	setnbr(int n, char *str, size_t len)
{
	long int	ln;
	size_t		first;

	ln = n;
	first = 0;
	if (ln < 0)
	{
		*str = '-';
		ln = -ln;
		++first;
	}
	while (len-- > first)
	{
		str[len] = ln % 10 + '0';
		ln /= 10;
	}
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	len = get_length(n);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	setnbr(n, str, len);
	str[len] = 0;
	return (str);
}
