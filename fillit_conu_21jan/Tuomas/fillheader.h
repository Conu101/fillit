/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillheader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:53:32 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/18 14:19:44 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLHEADER_H
# define FILLHEADER_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

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
	struct s_piece	*next;
}		t_piece;

typedef struct s_piecelist
{
	t_piece	**list;
	int		count;
	int		placed[26];
}	t_piecelist;

char	**ft_fillsplit(const char *s, char c);
int		ft_fill_count(char *s, char c);
int		get_next_line(const int fd, char **line);
int		ft_fill_amount(char *str);
char	**ft_fill_split(char **arr, char *str, int len);
void	ft_print_array(char **arr);
int		cmp_to_type(char **types, char *single);
int		*ft_assign_types(char **array, char **types, int size);
void	print_int_array(int *arr, int size);
int		*type_to_coords(int type);
int		*ft_array_atoi(char **array, int type);
int		ft_check_string(char *str);
int		*ft_strslice(char *str);
int		*set_voffset(int *array, int start, int offset);
int		*set_hoffset(int *array, int start);
t_piece		*makelist(int *coords, int count);
t_piece		*makepiece(int *coords, char letter,int start);
void	print_piece_array(t_piece *array, int count);
int		get_map_size(int count);
char	*ft_mapnew(size_t size);

#endif