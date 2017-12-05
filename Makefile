# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/11 21:55:52 by dverbyts          #+#    #+#              #
#    Updated: 2017/02/11 12:43:13 by dverbyts         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = fillit.c map.c open.c struct.c validate.c lib1.c lib2.c lib3.c
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

all : $(NAME)
$(NAME) : $(OBJS)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
