# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 10:25:06 by ctrouve           #+#    #+#              #
#    Updated: 2022/01/27 10:39:59 by ctrouve          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FUNCTIONS = abs_to_rel ft_check_string ft_recursive_factorial \
ft_strslice main makelist makemap makepiece placepiece run_fillit \
set_hoffset set_voffset solve
FILES = $(patsubst %, %.c, $(FUNCTIONS))
OBJECTS = $(patsubst %, %.o, $(FUNCTIONS))

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -Wall -Wextra -Werror -c $(FILES)
	gcc -Wall -Werror -Wextra $(OBJECTS) libft/libft.a -o $(NAME)
	make fclean -C libft/

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
