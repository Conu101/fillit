/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:56:33 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/18 14:20:46 by ctrouve          ###   ########.fr       */
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

typedef struct s_point
{
	int	row;
	int	column;
}	t_point;

typedef struct s_map
{
	char	**map_array;
	int		map_size;
}	t_map;

typedef struct s_piece
{
	char	letter;
	int		leader_coord[2];
	int		friends_coord[6];
	int		type;
	int		placed;
	int		lined;
	int		ingrid;
	struct s_piece	*next;
}		t_piece;

typedef struct s_piecelist
{
	t_piece	**list;
	int		count;
}	t_piecelist;

t_piece		*makepiece(int type, char letter);
int			attrib_friends_coord(type, i);
int			*ft_assign_types(char **array, char **types, int size);
t_map		*makemap(int map_size);
int			placepiece(t_piece *piece, t_map *map, int x_offset, int y_offset);
void		cancelplacepiece(t_piece *piece, t_map *map, int x_offset, int y_offset);

#endif
