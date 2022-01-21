/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_to_coords.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:44:45 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/17 15:54:20 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillheader.h"

int	*type_to_coords(int type)
{
	int		*coords;
	char	*str;
	char	**array;
	char	*tmp;
	int		fdret[2];

	//printf("\n%s\n", "break 2");
	fdret[0] = open("coords.txt", O_RDONLY);
	//printf("\n%d\n", fd);
	str = "";
	tmp = NULL;
	fdret[1] = 6;
	while (fdret[1] != 0)
	{
		fdret[1] = get_next_line(fdret[0], &tmp);
		if (fdret[1] != 0)
			str = ft_strjoin(str, tmp);
	}
	//printf("\n%s\n", "break 3");
	array = ft_strsplit(str, '#');
	//printf("\n%s\n", "break 4");
	//ft_print_array(array);
	coords = ft_array_atoi(array, (type - 1));
	return (coords);
}
	