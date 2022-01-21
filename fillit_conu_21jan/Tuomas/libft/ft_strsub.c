/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:08:08 by tburakow          #+#    #+#             */
/*   Updated: 2021/11/24 14:29:42 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*fsh;

	i = start;
	if (!s)
		return (NULL);
	fsh = (char *)malloc(sizeof(char) * (len + 1));
	if (!fsh)
		return (NULL);
	while ((i - start) < len)
	{
		fsh[i - start] = s[i];
		i++;
	}
	fsh[i - start] = '\0';
	return (fsh);
}
