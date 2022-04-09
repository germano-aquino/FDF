/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:08:32 by grenato-          #+#    #+#             */
/*   Updated: 2022/03/23 20:32:15 by grenato-         ###   ########.fr       */
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
# include "struct.h"
# include "macro.h"

void			ft_mlx_put_pixel(t_data *data, int x, int y, \
	unsigned int color);
void			ft_draw_line(t_point p0, t_point p1, t_data *img);
t_map			ft_get_map(char *str_to_map);
void			ft_free_map(t_map *map);
void			ft_free_2d_char_ptr(char ***ptr);
void			ft_free_2d_double_ptr(double ***ptr);
void			ft_swap(int *x, int *y);
void			ft_iso_projection(t_vars *vars);
void			ft_print_map(t_map *map);
int				ft_mouse_action(int button, int x, int y, t_vars *vars);
int				ft_key_action(int keycode, t_vars *vars);
int				ft_close(t_vars *vars);
t_data			ft_init_image(void *mlx);
double			**ft_init_base(void);
void			ft_rotate_axis(t_vars *vars, int keycode);
double			ft_dot_product(double vec1[3], double vec2[3]);
double			ft_get_norm(double *vec);
double			*ft_cross_product(double *vec1, double *vec2);
void			ft_translate_origin(t_vars *vars, int keycode);
void			ft_reload_image(t_vars *vars);
double			**ft_init_origin(t_map *map);
double			*ft_get_axis_angle(t_map *map);
double			**ft_project_axis_onto_plane(double **base);
int				ft_open_map_file(char *path_to_map);
t_quaternion	ft_quaternion_mult(t_quaternion x, t_quaternion y);
void			ft_store_min_and_max_z(t_map *map, int z);
unsigned int	ft_get_color(t_map *map, int z);
unsigned int	ft_get_line_color(t_line *line);
void			ft_show_instructions(t_vars *vars);
void			ft_show_projection(t_vars *vars, unsigned char c);
void			ft_para_x_projection(t_map *map, int scale, t_data *img);
void			ft_para_y_projection(t_map *map, int scale, t_data *img);
void			ft_para_z_projection(t_map *map, int scale, t_data *img);
void			ft_set_scale(t_vars *vars, int keycode);

#endif
