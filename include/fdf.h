#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <mlx.h>
#include "color.h"

#define WIDTH 960
#define HEIGHT 540

typedef struct s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}				t_data;

typedef struct s_env 
{
	void	*mlx;
	void	*win;
}				t_env;

void	my_mlx_put_pixel(t_data *data, int x, int y, unsigned int color);
void	chess_board(t_data *data, int step);
#endif

