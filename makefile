# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 17:55:55 by ssaadaou          #+#    #+#              #
#    Updated: 2023/05/28 18:58:30 by ssaadaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBRARY = so_long.h

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

SRC = main.c utils.c get_next_line.c get_next_line_utils.c \
	checking_errors.c split.c check_wall.c check_map_elements.c \
	put_window.c file_to_image.c position_player.c valid_path.c    

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

mc : all clean

%.o : %.c $(LIBRARY)
	$(CC) $(CFLAGS) -Imlx -c  $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all