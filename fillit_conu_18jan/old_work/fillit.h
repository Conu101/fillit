/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:11:46 by ctrouve           #+#    #+#             */
/*   Updated: 2022/01/15 13:57:34 by ctrouve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define BUFF_SIZE 200

char	**ft_fillsplit(const char *s, char c);
int		ft_fill_count(char *s, char c);
int		get_next_line(const int fd, char **line);
int		ft_fill_amount(char *str);
char	**ft_fill_split(char **arr, char *str, int len);
void	ft_print_array(char **arr);
int		cmp_to_type(char **types, char *single);
int		*ft_assign_types(char **array, char **types);
void	print_int_array(int *arr);

typedef struct s_piece
{
	char			letter;
	int				type[19];
	int				x_pos;
	int				y_pos;
	struct s_piece	*next_piece;
}	t_piece;

typedef struct s_map
{
	char	**map_array;
	int		size;
}	t_map;

#endif
