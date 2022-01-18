/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:56:13 by nsamoilo          #+#    #+#             */
/*   Updated: 2021/11/26 11:40:23 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
}

static	int	count_words(char const *s, char c)
{
	int	i;
	int	words;
	int	is_word;

	i = 0;
	is_word = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && is_word)
			is_word = 0;
		else if (s[i] != c && !is_word)
		{
			is_word = 1;
			words++;
		}
		i++;
	}
	return (words);
}

static	int	count_len(char const *s, char c, size_t i)
{
	size_t	len;

	len = 0;
	while (s[len + i] && s[len + i] != c)
		len++;
	return (len);
}

static	int	split_words(char const *s, char c, char **array)
{
	size_t	i;
	int		words;
	int		len;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = count_len(s, c, i);
			array[words] = ft_strsub(s, i, len);
			if (array[words] == NULL)
			{
				free_array(array);
				return (0);
			}
			i = i + len;
			words++;
		}
	}
	return (1);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		words;

	words = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (array == NULL)
		return (NULL);
	if (!split_words(s, c, array))
		return (NULL);
	array[words] = 0;
	return (array);
}
