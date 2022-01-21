/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:40:42 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/18 11:51:14 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillheader.h"

void	print_int_array(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		printf("\n%d\n", arr[i]);
		i++;
		j++;
		if (j % 8 == 0)
			printf("\n%s\n", "New tetrimino!");
	}
	printf("\n");
}
