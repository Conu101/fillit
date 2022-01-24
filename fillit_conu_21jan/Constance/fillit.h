/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:56:33 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/23 15:28:16 by ctrouve          ###   ########.fr       */
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

typedef struct s_map
{
	char	**map_array;
	int		map_size;
}	t_map;

typedef struct s_piece
{
	char	letter;
//	int		rank; used in Tuomas' functions ??
	int		leader_coord[2];
	int		friends_coord[6];
	struct s_piece	*next;
}	t_piece;


void		cancelplacepiece(t_piece *piece, t_map *map);
void		free_map(t_map *map, int map_size);
void		print_map(t_map *map, int size);
int			allblocksinmap(t_piece *piece, t_map *map, int x_offset, int y_offset);
int			*attrib_leader_coord(int *piece_coord_array, int i);
int			*attrib_friends_coord(int *piece_coord_array, int i);
int			get_map_size(int count);
int			mapready(t_map *map, int count);
int			placepiece(t_piece *piece, t_map *map, int x_offset, int y_offset);
int			solve(t_piece *piecelist, t_map *map, int x_offset, int y_offset, int count);
t_piece		*makepiece(int *coords, char letter, int start);
t_piece		*makelist(int *list_coord_array, int count);
t_map		*makemap(int map_size);
t_map		*increase_mapsize(t_map *map);
int			*set_voffset(int *array, int start, int offset);
int			*set_hoffset(int *array, int start);
int			ft_check_string(char *str);
int			*ft_strslice(char *str);
int			*abs_to_rel(int *coords, int start, int lead_ver, int lead_hor);

#endif
