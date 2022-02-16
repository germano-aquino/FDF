# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 19:19:45 by grenato-          #+#    #+#              #
#    Updated: 2022/02/16 17:37:36 by grenato-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# define the C compiler
CC = clang

# define any compile-time flags
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=256

# name of the project
NAME = fdf

ANAME = fdf.a

INCLUDE = include

SRC_DIR = src

MLX_DIR = mlx_linux

MLX = mlx_linux/libmlx_Linux.a

LIBFT_DIR = libft

LIBFT = libft/libft.a

C_SOURCE = $(SRC_DIR)/fdf.c\
			$(SRC_DIR)/get_next_line.c\
			$(SRC_DIR)/map.c\
			$(SRC_DIR)/line.c\
			$(SRC_DIR)/utils.c


%.o: %.c
	$(CC) $(CLFLAGS) -I/usr/include -I$(MLX_DIR) -I$(INCLUDE) -I$(LIBFT_DIR) -O3 -c $< -o $@

OBJ = $(C_SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT) $(ANAME)
	ar rcs $(ANAME) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(ANAME) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -I$(INCLUDE) -lXext -lX11 -lm -lz -o $(NAME)

bonus: all

clean:
	rm -rf $(OBJ)
	$(MAKE) -C ${MLX_DIR} clean
	$(MAKE) -C ${LIBFT_DIR} clean

fclean: clean
	rm -rf ${NAME} ${ANAME}
	$(MAKE) -C ${MLX_DIR} fclean
	$(MAKE) -C ${LIBFT_DIR} fclean

re: fclean all