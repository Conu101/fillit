# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 14:28:06 by nsamoilo          #+#    #+#              #
#    Updated: 2021/11/26 11:35:56 by nsamoilo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FUNCTIONS = ft_putchar ft_putchar_fd ft_putstr ft_putstr_fd ft_putendl \
			ft_putendl_fd ft_itoa ft_putnbr ft_putnbr_fd ft_strnew ft_strdel \
			ft_strclr ft_striter ft_striteri ft_strlen ft_strmap ft_strmapi \
			ft_strequ ft_strnequ ft_isalpha ft_isdigit ft_isalnum ft_isascii \
			ft_isprint ft_toupper ft_tolower ft_atoi ft_strdup ft_strcpy \
			ft_strncpy ft_strcat ft_strncat ft_strlcat ft_strchr ft_strrchr \
			ft_strcmp ft_strncmp ft_strstr ft_strnstr ft_memset ft_memalloc \
			ft_memdel ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr \
			ft_memcmp ft_strsub ft_strjoin ft_strtrim ft_strsplit \
			ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter \
			ft_lstmap ft_lstprint ft_strisx ft_calloc ft_lstaddend ft_strrev
FILES = $(patsubst %, %.c, $(FUNCTIONS))
OBJECTS = $(patsubst %, %.o, $(FUNCTIONS))

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(FILES)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:
	@for function in $(FUNCTIONS) ; do \
		./eval_tests/tests.sh $$function ; \
	done
