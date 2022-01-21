/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:53:34 by tburakow          #+#    #+#             */
/*   Updated: 2021/12/16 01:07:15 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_it_w(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char	*ft_strtrim(const char *s)
{
	char	*fsh;
	size_t	end;
	size_t	start;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	end = ft_strlen(s) - 1;
	start = 0;
	while (is_it_w(s[start]) == 1 && ft_strlen(s) > 0)
		start++;
	while (is_it_w(s[end]) == 1 && end >= 1)
		end--;
	if (start >= end || ft_strcmp(s, "") == 0)
		return (ft_strnew(0));
	fsh = (char *)malloc(sizeof(char) * end - start + 2);
	if (!fsh)
		return (NULL);
	while (start <= end)
		fsh[i++] = s[start++];
	fsh[i] = '\0';
	return (fsh);
}
