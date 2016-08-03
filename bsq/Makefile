# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asun <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/03 12:09:44 by asun              #+#    #+#              #
#    Updated: 2016/08/03 12:09:45 by asun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	bsq
SRCS	=	calculate.c \
			main.c \
			read.c \
			ft.c
OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
CFLAGS	+=	-c -Wall -Werror -Wextra

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

$(OBJS):
	$(CC) $(CFLAGS) $(SRCS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
