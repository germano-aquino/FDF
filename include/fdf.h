/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:08:32 by grenato-          #+#    #+#             */
/*   Updated: 2022/02/16 17:34:28 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <mlx.h>
#include <errno.h>
#include "color.h"
#include "get_next_line.h"
#include "libft.h"

#define WIDTH 960
#define HEIGHT 540
#define ESC 27

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
}				t_vars;

void	ft_mlx_put_pixel(t_data *data, int x, int y, unsigned int color);
void	ft_draw_line(int x0, int y0, int x1, int y1, t_data *img);
void	ft_get_map(t_map *map, char *str_to_map);
void	ft_free_map(t_map *map);
void	ft_free_2d_ptr(char ***ptr);
#endif

