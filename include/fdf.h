/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:08:32 by grenato-          #+#    #+#             */
/*   Updated: 2022/02/23 00:41:11 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <errno.h>
# include "color.h"
# include "get_next_line.h"
# include "libft.h"

# define WIDTH 960
# define HEIGHT 540

# define ESC 27

# define ISO_ORIGIN_X WIDTH / 3
# define ISO_ORIGIN_Y HEIGHT / 5

# define ISO_X_ANGLE M_PI / 6
# define ISO_Y_ANGLE 5 * M_PI / 6
# define ISO_Z_ANGLE 3 * M_PI / 2

# define SCALE_DEFAULT 10

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}				t_point;

typedef struct s_line
{
	t_point	p0;
	t_point	p1;
	int		dx;
	int		dy;
	int		stepx;
	int		stepy;
	int		inv;
}				t_line;

typedef struct s_map
{
	int		height;
	int		width;
	t_point	**grid;
}				t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}				t_data;

typedef struct s_vars 
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_map	map;
	int		scale;
}				t_vars;

void	ft_mlx_put_pixel(t_data *data, int x, int y, unsigned int color);
void	ft_draw_line(t_point p0, t_point p1, t_data *img);
void	ft_get_map(t_map *map, char *str_to_map);
void	ft_free_map(t_map *map);
void	ft_free_2d_ptr(char ***ptr);
void	ft_swap(int *x, int *y);

void	ft_iso_projection(t_vars *vars);
void	ft_print_map(t_vars *vars);
#endif

