/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:56:33 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/21 16:37:24 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include <string.h>
# include <sys/stat.h>
# include <stdio.h>

/*
typedef struct s_point
{
	int	row;
	int	column;
}	t_point;
*/

/*typedef struct s_map
{
	char	**map_array;
	int		map_size;
}	t_map;

typedef struct s_piece
{
	char	letter;
	int		rank;
	int		topleft_x;
	int		topleft_y;
	int		leader_coord[2];
	int		friends_coord[6];
	int		placed;
	int		lined;
	int		ingrid;
	struct s_piece	*next;
}	t_piece;

typedef struct s_piecelist
{
	//int		*list;
	t_piece	*first;
	t_piece	*current;
	int		tetricount;
}	t_piecelist;*/

int		ft_check_string(char *str);
int		*split_and_offset(char *str, size_t *jkl, size_t len, int *coords);
void	set_voffset(int *coords, int start, int offset);
void	abs_to_rel(int *coords, int start, int lead_ver, int lead_hor);
void	set_relative(int *coords, int start);
void	set_hoffset(int *array, int start);

#endif
