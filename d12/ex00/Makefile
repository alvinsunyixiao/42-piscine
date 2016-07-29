# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asun <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/28 10:49:38 by asun              #+#    #+#              #
#    Updated: 2016/07/28 10:49:39 by asun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_display_file
LIB_SRCS	=	ft_putchar.c \
				ft_putstr.c \
				ft_strcmp.c \
				ft_strlen.c \
				ft_swap.c \
				ft_puterr.c
LIB_OBJS =		$(LIB_SRCS:.c=.o)
SRC =	ft_display_file.c
OBJ =	$(SRC:.c=.o)
LIB_NAME =	libft.a
CFLAGS +=	-Wall -Werror -Wextra -c
CC = gcc

all: $(NAME)

$(NAME): libmake
	$(CC) $(CFLAGS) $(SRC)
	$(CC) -o $(NAME) $(OBJ) -L. -lft

lib:
	$(CC) $(CFLAGS) $(LIB_SRCS)
	ar rc $(LIB_NAME) $(LIB_OBJS)
	ranlib $(LIB_NAME)

libclean:
	/bin/rm -f $(LIB_OBJS)

libmake: lib libclean

clean: libclean
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME) $(LIB_NAME)

re: fclean all
