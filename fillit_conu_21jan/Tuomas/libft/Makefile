#  #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 14:07:00 by tburakow          #+#    #+#              #
#    Updated: 2021/11/15 16:21:55 by tburakow         ###   ########.fr        #
#                                                                              #
#  #

NAME = libft.a

SRCS = $(foreach src, $(FUNCS), $(addsuffix .c, $(src)))

OBJS = $(foreach obj, $(FUNCS), $(addsuffix .o, $(obj)))

FUNCS = ft_isalpha \
	ft_isdigit \
	ft_isalnum \
	ft_isascii \
	ft_isprint \
	ft_toupper \
	ft_tolower \
	ft_strlen \
	ft_strdup \
	ft_strcpy \
	ft_strcat \
	ft_strncat \
	ft_strlcat \
	ft_strchr \
	ft_strrchr \
	ft_strstr \
	ft_strnstr \
	ft_strcmp \
	ft_strncmp \
	ft_atoi \
	ft_memset \
	ft_bzero \
	ft_memcpy \
	ft_memccpy \
	ft_memmove \
	ft_memchr \
	ft_memcmp \
	ft_memalloc \
	ft_memdel \
	ft_strnew \
	ft_strdel \
	ft_strclr \
	ft_striter \
	ft_striteri \
	ft_strmapi \
	ft_strmap \
	ft_strequ \
	ft_strnequ \
	ft_strsub \
	ft_strjoin \
	ft_strtrim \
	ft_strsplit \
	ft_itoa \
	ft_putchar \
	ft_putstr \
	ft_putendl \
	ft_putnbr \
	ft_putchar_fd \
	ft_putstr_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_strnew \
	ft_lstnew \
	ft_lstdelone \
	ft_lstdel \
	ft_lstadd \
	ft_lstiter \
	ft_lstmap \
	ft_word_count \
	ft_strncpy\
	ft_free_array
		 
all:	$(NAME)
	
$(NAME):	$(SRCS)
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
