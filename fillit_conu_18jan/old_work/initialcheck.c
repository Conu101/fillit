/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:23:54 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/15 13:57:34 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*make_tetriarray(char *buff, ssize_t n_bytes)
{

}

/* Reads characters from the input file and stores null-terminated, 
** 546 char-long string into buffer.
*/
t_piece	*initialcheck(char *fd_file)
{
	char	buff[546];
	int		fd;
	ssize_t	n_bytes;

	fd = open(fd_file, O_RDONLY);
	n_bytes = read(fd, buff, 546);
	close(fd);
	if (n_bytes > 546 || n_bytes < 20)
		return (NULL);
	buff[n_bytes - 1] = '\0';
	return (make_tetriarray(buff, n_bytes));
}
