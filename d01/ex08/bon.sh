# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    bon.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asun <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/12 18:01:03 by asun              #+#    #+#              #
#    Updated: 2016/07/13 17:01:19 by asun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

ldapsearch -Q | grep "cn: " | grep "bon" | wc -l | tr -d ' '
