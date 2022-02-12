# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 10:25:06 by ctrouve           #+#    #+#              #
#    Updated: 2022/02/04 12:30:38 by tburakow         ###   ########.fr        #
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
	gcc -Wall -Wextra -Werror -c -g $(FILES)
	gcc -Wall -Werror -Wextra -g $(OBJECTS) libft/libft.a -o $(NAME)
	make fclean -C libft/

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
