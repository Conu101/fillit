/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piece_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:39:35 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/18 13:56:33 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillheader.h"

void	print_piece_array(t_piece *array, int count)
{
	int	i;
	int j;
	
	j = 0;
	i = 0;
	while (j < count)
	{
		printf("\n%s\n", "New Tetrimino!");
		while (i < 2)
		{
			printf("%d\n", array[j].leader_coord[i]);
			i++;
		}
		i = 0;
		while (i < 6)
		{
			printf("%d\n", array[j].friends_coord[i]);
			i++;
		}
		printf("%c\n", array[j].letter);
		i = 0;
		j++;
	}
}
