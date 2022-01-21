/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:57:46 by tburakow          #+#    #+#             */
/*   Updated: 2021/11/30 12:54:56 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_lgt(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static char	*popul_str(char *str, int *im, int n)
{	
	str[im[0]--] = '\0';
	while (im[0] >= 0)
	{
		str[im[0]--] = (n % 10 + '0');
		n = n / 10;
		if (im[0] == 0 && im[1] != 0)
			str[im[0]--] = '-';
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		im[2];
	char	*str;

	im[0] = 0;
	im[1] = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		im[1] = 1;
		n = n * -1;
	}
	str = (char *)malloc(sizeof(char) * (unsigned long)nbr_lgt(n) + \
	(unsigned long)im[1] + 1);
	if (!str)
		return (NULL);
	im[0] = (nbr_lgt(n) + im[1]);
	str = popul_str(str, im, n);
	return (str);
}
