# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 19:19:45 by grenato-          #+#    #+#              #
#    Updated: 2022/02/07 22:51:01 by grenato-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# define the C compiler
CC = clang

# define any compile-time flags
CFLAGS = -Wall -Wextra -Werror 

# name of the project
NAME = fdf

INCLUDE = include

SRC_DIR = src

MLX_DIR = mlx_linux

MLX = mlx_linux/libmlx_Linux.a

C_SOURCE = main.c

%.o: %.c
	$(CC) $(CLFLAGS) -I/usr/include -I$(MLX_DIR) -I$(INCLUDE) -O3 -c $< -o $@

OBJ = $(C_SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -I$(INCLUDE) -lXext -lX11 -lm -lz -o $(NAME)

bonus: all

clean:
	rm -rf $(OBJ)
	$(MAKE) -C ${MLX_DIR} clean

fclean: clean
	rm -rf ${NAME}
	$(MAKE) -C ${MLX_DIR} fclean

re: fclean all