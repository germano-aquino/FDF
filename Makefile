# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 19:19:45 by grenato-          #+#    #+#              #
#    Updated: 2022/03/26 15:51:22 by grenato-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# define the C compiler
CC = clang
#CC = gcc

# define any compile-time flags
CFLAGS = -Wall -Wextra -Werror -g -D BUFFER_SIZE=256

# library flags
LDFLAGS = -L. -lz -lm -lmlx -lXext -lX11

# name of the project
NAME = fdf

INCLUDE = include

SRC_DIR = src

LIBFT_DIR = libft

LIBFT = libft/libft.a

HEADERS = -I/usr/include -I$(INCLUDE) -I$(LIBFT_DIR)

OBJ_DIR = obj

SOURCE_FILES = fdf.c get_next_line.c map.c translation.c
SOURCE_FILES += line.c utils.c isometric_projection.c 
SOURCE_FILES += rotation.c map_utils.c vector.c color.c
SOURCE_FILES += instructions.c parallel_projection.c free.c


C_SOURCE = $(addprefix $(SRC_DIR)/, $(SOURCE_FILES))

OBJ = $(C_SOURCE:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CLFLAGS) $(HEADERS) -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(HEADERS) $(OBJ) -o $(NAME) $(LIBFT) $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

bonus: all

clean:
	rm -rf $(OBJ)
	$(MAKE) -C ${LIBFT_DIR} clean

fclean: clean
	rm -rf ${NAME}
	$(MAKE) -C ${LIBFT_DIR} fclean

re: fclean all