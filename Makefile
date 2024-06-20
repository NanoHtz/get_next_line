# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 19:08:40 by fgalvez-          #+#    #+#              #
#    Updated: 2024/06/20 18:59:16 by fgalvez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = get_next_line.a
INCLUDE = get_next_line.h
SRC = get_next_line.c \
    get_next_line_utils.c

OBJ = $(SRC:.c=.o)
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
        @ar -crs $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
    $(CC) $(CFLAGS) -DBUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re: fclean all