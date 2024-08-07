# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 19:08:40 by fgalvez-          #+#    #+#              #
#    Updated: 2024/06/20 19:47:23 by fgalvez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = get_next_line.a
EXEC = get_next_line_exec

INCLUDE = get_next_line.h

SRC = get_next_line.c \
	get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME) $(EXEC)

$(NAME): $(OBJ)
		@ar -crs $(NAME) $(OBJ)

$(EXEC): $(OBJ) main.o
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ) main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

BUFFER_SIZE = 1024

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -DBUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
