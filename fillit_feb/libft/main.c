/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:52:11 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/04 12:00:38 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	error_output(void)
{
	ft_putstr("error\n");
	return (1);
}

static int	check_dots(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			j++;
		i++;
	}
	if (j != (ft_strlen(str) + 1) / 21 * 12)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		fd;
	int		count;
	int		*coords;

	if (argc != 2)
	{
		ft_putstr("usage: enter one filename only after the executable.\n");
		return (1);
	}
	str = (char *)malloc(sizeof(char) * 546);
	fd = open(argv[1], O_RDONLY);
	read(fd, str, 547);
	if (str[546] != '\0' || check_dots(str) == 0)
		return (error_output());
	close(fd);
	count = ((ft_strlen(str) + 1) / 21);
	if (fd == -1 || ft_check_string(str) != 1 || ft_strlen(str) % 21 != 20)
		return (error_output());
	coords = create_coords(str);
	if (!coords)
		return (error_output());
	run_fillit(coords, count);
	return (0);
}
