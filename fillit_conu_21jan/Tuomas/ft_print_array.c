/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:41:06 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/15 11:10:39 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillheader.h"

void	ft_print_array(char **arr)
{
	int	i;
	
	i = 0;
	while (arr[i])
	{
		printf("\n%s\n", arr[i]);
		//printf("\n%d\n", i);
		i++;
	}
}