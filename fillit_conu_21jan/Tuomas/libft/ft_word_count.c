/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:19:52 by tburakow          #+#    #+#             */
/*   Updated: 2021/11/26 16:24:52 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_del(char z, char c)
{
	if (z == c)
		return (1);
	return (0);
}

int	ft_word_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (is_del(s[i], c) == 1 && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if (is_del(s[i], c) == 0)
		{
			if ((is_del(s[i - 1], c) == 1))
				count++;
			if (i == 0)
				count++;
		}
		i++;
	}
	return (count);
}
