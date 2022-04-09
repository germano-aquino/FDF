/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:01:34 by grenato-          #+#    #+#             */
/*   Updated: 2022/03/23 20:31:48 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_quaternion
{
	double	vec[3];
	double	re;
}				t_quaternion;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}				t_point;

typedef struct s_rectangle
{
	t_point			p0;
	t_point			p1;
	int				width;
	int				height;
}				t_rectangle;

typedef struct s_line
{
	t_point			p0;
	t_point			p1;
	t_point			init;
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
	int		min_z;
	int		max_z;
	double	**vec_base;
	double	**proj_base;
	double	*axis_angle;
	t_point	origin;
	t_point	**grid;
}				t_map;

typedef struct s_data
{
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
	int		proj;
}				t_vars;

#endif