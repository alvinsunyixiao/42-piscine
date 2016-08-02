# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asun <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/30 21:27:19 by asun              #+#    #+#              #
#    Updated: 2016/07/31 13:51:32 by srodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	rush-2
CFLAGS += 	-c -Wall -Wextra -Werror
CFILES = 	compare.c \
			ft_create_elem.c \
			ft_list_push_front.c \
			ft_putchar.c \
			ft_putline.c \
			ft_putnbr.c \
			ft_putstr.c \
			rush.c \
			rush00.c \
			rush01.c \
			rush02.c \
			rush03.c \
			rush04.c
OFILES =	$(CFILES:.c=.o)
CC =  		gcc

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(OFILES) -o $(NAME)

$(OFILES):
	$(CC) $(CFLAGS) $(CFILES)

clean:
	/bin/rm -rf $(OFILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
