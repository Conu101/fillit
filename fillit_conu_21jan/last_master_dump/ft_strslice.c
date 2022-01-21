/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:12:54 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/21 13:29:02 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	cnt_link_test(size_t *cnt_link_len)
{
	if (cnt_link_len[1] % 3 != 0 && cnt_link_len[0] % 4 != 0 && \
	cnt_link_len[1] % 4 != 0)
		return (0);
	return (1);
}

void	offset(int *ret, int k)
{
	int	end;
	int	last;
	int	offset;
	int	orig;
	int	start;

	end = k + 7;
	offset = 0;
	start = k;
	orig = start;
	last = 100;
	set_voffset(&ret, (k - 8), ret[k - 8]);
	while (start < end)
	{
		if (ret[start] != 0 && ret[start] < last)
			offset = ret[start];
		last = offset;
		start += 2;
	}
	while (orig < start)
	{
		ret[orig] = ret[orig] - offset;
		orig += 2;
	}
}

int	get_map_size(int count)
{
	int	map_size;

	map_size = 2;
	while (map_size * map_size < 4 * count)
		map_size++;
	return (map_size);
}

static void	count_and_link(size_t *cnt_link, char **str, int j)
{
	cnt_link[0]++;
	if (str[j + 1] == '#')
		cnt_link[1]++;
	if (str[j + 5] == '#')
		cnt_link[1]++;
}

int	*slice_and_offset(char *str, size_t j, size_t k, int truth)
{
	int		*ret;
	size_t	cnt_link_len[3];

	cnt_link_len[2] = ft_strlen(str);
	while (j < cnt_link_len[2])
	{
		cnt_link_len[0] = 0;
		cnt_link_len[1] = 0;
		while (j % 21 != 0 || truth == 0)
		{
			truth = 1;
			if (str[j++] == '#')
			{
				count_and_link(cnt_link_len, &str, j);
				ret[k++] = (j - 1) % 21 / 5 % 5;
				ret[k++] = (j - 1) % 21 % 5;
			}
		}
		if (cnt_link_test(cnt_link_len) == 0)
			return (NULL);
		truth = 0;
	}
	return (ret);
}
