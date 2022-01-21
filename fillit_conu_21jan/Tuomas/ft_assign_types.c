/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:32:09 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/15 13:30:11 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillheader.h"

int	*ft_assign_types(char **array, char **types, int size)
{
	int	i;
	int *ret;

	i = 0;
	ret = (int *)malloc(sizeof(int) * (size));
	while (array[i] != NULL)
	{
		//printf("\n%d\n", ret[i]);
		ret[i] = cmp_to_type(types, array[i]);
		//printf("\n%d\n", ret[i]);
		i++;
	}
	return (ret);
}