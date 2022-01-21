/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:38:33 by ctrouve           #+#    #+#             */
/*   Updated: 2021/11/11 18:38:33 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_putendl_fd() function outputs a string to the output specified by
** the file descriptor, followed by a newline. The file descriptor  can be  0,
** 1, or 2, to refer to standard input, standard output, or standard error,
** respectively.
*/

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
		ft_putchar_fd('\n', fd);
	}
}
