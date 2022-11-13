# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctrouve <ctrouve@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 10:25:06 by ctrouve           #+#    #+#              #
#    Updated: 2022/02/08 15:18:42 by ctrouve          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FUNCTIONS = create_coords ft_check_string ft_recursive_factorial \
main makelist makemap makepiece placepiece run_fillit \
set_hoffset set_voffset solve set_relative

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
