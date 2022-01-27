/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:52:11 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/27 10:22:49 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	*str;
	int		fd;
	int		ret;
	int		count;

	if (argc != 2)
	{
		ft_putstr("usage: enter one filename only after the executable.\n");
		return (1);
	}
	str = (char *)malloc(sizeof(char) * 546);
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, str, 546);
	str[ret] = '\0';
	count = (ft_strlen(str) / 21);
	if (fd == -1 || ft_check_string(str) != 1)
	{
		ft_putstr("error\n");
		return (1);
	}
	run_fillit(str, count);
	return (0);
}
