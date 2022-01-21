/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:45:18 by tburakow          #+#    #+#             */
/*   Updated: 2021/12/07 14:28:04 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_del(char z, char c)
{
	if (z == c)
		return (1);
	return (0);
}

static char	**popul_arr(size_t *ijk, char **arr, size_t wc, char *s)
{
	arr[ijk[2]++] = ft_strsub(s, (unsigned int)ijk[1], \
	(ijk[0]++ - ijk[1]));
	if (!arr[ijk[2] - 1])
		ft_free_array(arr, wc);
	return (arr);
}

static char	**word_input(char *s, char c, char **arr, size_t wc)
{
	size_t	ijk[3];

	ijk[0] = 0;
	ijk[1] = 0;
	ijk[2] = 0;
	if (!s)
		return (NULL);
	while (is_del(s[ijk[0]], c) == 1 && s)
		ijk[0]++;
	while (s[ijk[0]] != '\0' && ijk[0] < ft_strlen(s))
	{
		while (is_del(s[ijk[0]], c) == 1)
			ijk[0]++;
		ijk[1] = ijk[0];
		while (is_del(s[ijk[0]], c) == 0 && ijk[0] < ft_strlen(s))
			ijk[0]++;
		if (ijk[2] < wc)
			arr = popul_arr(ijk, arr, wc, s);
	}
	arr[ijk[2]] = NULL;
	return (arr);
}

char	**ft_strsplit(const char *s, char c)
{
	char	**arr;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * \
	(unsigned long)(ft_word_count((char *)s, c) + 1));
	if (!arr)
		return (NULL);
	arr = word_input((char *)s, c, arr, (size_t)(ft_word_count((char *)s, c)));
	return (arr);
}
