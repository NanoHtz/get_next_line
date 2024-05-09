# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 19:08:40 by fgalvez-          #+#    #+#              #
#    Updated: 2024/05/09 16:29:00 by fgalvez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -DBUFER_SIZE=1024
NAME = get_next_line.a
INCLUDE = get_next_line.h
SRC = get_next_line.c \
	get_next_line_utils.c

OBJ = $(SRC:.c=.o)
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
		@ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all