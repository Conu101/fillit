/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:37:02 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/10 17:38:29 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	find_start(char const *s, int len)
{
	int	i;

	i = 0;
	while (i < len && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	return (i);
}

static	int	find_end(char const *s, int len)
{
	int	i;

	i = len - 1;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		len;
	char	*new;

	len = ft_strlen(s);
	start = find_start(s, len);
	end = find_end(s, len);
	len = end - start + 1;
	if (len < 0)
		len = 0;
	new = ft_strsub(s, start, (size_t) len);
	if (new == NULL)
		return (NULL);
	return (new);
}
