# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qle-bevi <qle-bevi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/29 23:23:47 by qle-bevi          #+#    #+#              #
#    Updated: 2016/03/09 21:35:08 by qle-bevi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_countwords.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isescaped.c ft_isprint.c ft_itoa.c ft_memalloc.c \
ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c \
ft_memset.c ft_pow.c ft_pushchar.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlen.c \
ft_strlcat.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_getdecade.c ft_lstnew.c \
ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstpush.c ft_lstmap.c \
ft_lstsort.c ft_lstsize.c ft_lstrev.c ft_lstgot.c ft_errexit.c 

INCLUDES = includes

OBJ = $(subst .c,.o,$(SRC))

FLAG = -Wall -Wextra -Werror -I$(INCLUDES)

all: $(NAME)

$(NAME):
	@gcc -c $(SRC) $(FLAG)
	@ar rc $(NAME) $(OBJ)
	@echo "\n✅  LIBFT BUILT !"

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re: fclean all
