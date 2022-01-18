/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:59:48 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/15 13:57:34 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_piece	*tetrifile;

	if (argc != 2)
	{
		ft_putendl("usage: enter only one parameter");
		return (-1);
	}
	if (initialcheck(argv[1] == NULL))
	{
		ft_putendl("error");
		return (-1);
	}
	solve(tetrifile);
	return (0);
}
