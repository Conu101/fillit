/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:12:54 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/18 11:39:27 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillheader.h"

int	*ft_strslice(char *str)
{
	size_t	j;
	size_t	k;
	int *ret;
	int cnt_link[2];
	int	truth;
	
	truth = 0;
	j = 0;
	k = 0;
	cnt_link[0] = 0;
	cnt_link[1] = 0;	
	ret = (int *)malloc(sizeof(int) * ((ft_strlen(str) / 21) * 8));
	while (j < ft_strlen(str))
	{
		while (j % 21 != 0 || truth == 0)
		{
			truth = 1;
			if (str[j] == '#')
			{
				cnt_link[0]++;
				if (str[j + 1] == '#')
					cnt_link[1]++;
				if (str[j + 5] == '#')
					cnt_link[1]++;
				ret[k] = j % 21 / 5 % 5;
				//printf("\nretk%d\n", ret[k]);
				ret[k + 1] = j % 21 % 5;
				//printf("\nretk+%d\n", ret[k + 1]);
				k += 2;
			}
			j++;
		}
		if (ret[k - 8] != 0)
			ret = set_voffset(ret, (k - 8), ret[k - 8]);
		ret = set_hoffset(ret, (k - 7));
		if (((cnt_link[0] % 4)  != 0 && (cnt_link[1] % 3) != 0) && ((cnt_link[0] % 4) != 0 && (cnt_link[1] % 4) != 0))
			return NULL;
		cnt_link[0] = 0;
		cnt_link[1] = 0;
		//i += 21;
		truth = 0;
	}
	return (ret);
}
