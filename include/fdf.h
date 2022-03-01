/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:08:32 by grenato-          #+#    #+#             */
/*   Updated: 2022/02/28 23:44:30 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <errno.h>
# include <stdio.h>
# include "color.h"
# include "get_next_line.h"
# include "libft.h"
# include "keycode.h"

# define WIDTH 960
# define HEIGHT 540

# define ISO_ORIGIN_X WIDTH / 3
# define ISO_ORIGIN_Y HEIGHT / 5

# define ISO_X_ANGLE M_PI / 6
# define ISO_Y_ANGLE 5 * M_PI / 6
# define ISO_Z_ANGLE 3 * M_PI / 2

# define DELTA M_PI / 60
# define SCALE_DEFAULT 10

typedef struct s_quaternion
{
	double	vec[3];
	double	real;
}				t_quaternion;


typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}				t_point;

typedef struct s_line
{
	t_point			p0;
	t_point			p1;
	int				dx;
	int				dy;
	int				stepx;
	int				stepy;
	int				inv;
	unsigned int	color;
}				t_line;

typedef struct s_map
{
	int		height;
	int		width;
	double	**vec_base;
	double	**proj_base;
	double	*axis_angle;
	t_point	origin;
	t_point	**grid;
}				t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
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
t_map	ft_get_map(char *str_to_map);
void	ft_free_map(t_map *map);
void	ft_free_2d_char_ptr(char ***ptr);
void	ft_free_2d_double_ptr(double ***ptr);
void	ft_swap(int *x, int *y);

void	ft_iso_projection(t_vars *vars);
void	ft_print_map(t_map *map);

int		ft_mouse_action(int button, int x, int y, t_vars *vars);
int		ft_key_action(int keycode, t_vars *vars);
void	ft_close(t_vars *vars);
t_data	ft_init_image(void *mlx);

void	ft_rotate_axis(t_vars *vars, int keycode);
double	ft_dot_product(double vec1[3], double vec2[3]);
double	ft_get_norm(double *vec);
double	*ft_cross_product(double *vec1, double *vec2);

void	ft_translate_origin(t_vars *vars, int keycode);
void	ft_reload_image(t_vars *vars);

double	**ft_init_origin(t_map *map);
double	*ft_get_axis_angle(t_map *map);
double	**ft_project_axis_onto_plane(double **base);
int		ft_open_map_file(char *path_to_map);

#endif
