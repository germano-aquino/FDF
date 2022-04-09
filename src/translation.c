/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:20:00 by grenato-          #+#    #+#             */
/*   Updated: 2022/03/18 16:37:11 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdio.h>

void	ft_reload_image(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img = ft_init_image(vars->mlx);
	if (vars->proj == 0)
		ft_iso_projection(vars);
	if (vars->proj == 1)
		ft_para_x_projection(&vars->map, vars->scale, &vars->img);
	if (vars->proj == 2)
		ft_para_y_projection(&vars->map, vars->scale, &vars->img);
	if (vars->proj == 3)
		ft_para_z_projection(&vars->map, vars->scale, &vars->img);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	ft_show_projection(t_vars *vars, unsigned char c)
{
	if (vars->map.vec_base != NULL)
		ft_free_2d_double_ptr(&vars->map.vec_base);
	vars->map.vec_base = ft_init_origin(&vars->map);
	if (c == '\t' || c == 'i')
		vars->proj = 0;
	if (c == 'x')
		vars->proj = 1;
	if (c == 'y')
		vars->proj = 2;
	if (c == 'z')
		vars->proj = 3;
	ft_reload_image(vars);
}

void	ft_translate_origin(t_vars *vars, int direction)
{
	int		step;
	t_point	*origin;

	origin = &vars->map.origin;
	step = 10;
	if (direction == UP)
		origin->y -= step;
	if (direction == DOWN)
		origin->y += step;
	if (direction == RIGHT)
		origin->x += step;
	if (direction == LEFT)
		origin->x -= step;
	ft_reload_image(vars);
}

int	ft_mouse_action(int button, int x, int y, t_vars *vars)
{
	int	step;

	step = 1;
	if (button == SCROLL_UP)
		vars->scale += step;
	if (button == SCROLL_DOWN)
		vars->scale -= step;
	ft_reload_image(vars);
	return (0);
}

void	ft_set_scale(t_vars *vars, int keycode)
{
	int	step;

	step = 1;
	if (keycode == PLUS)
		vars->scale += step;
	if (keycode == MINUS)
		vars->scale -= step;
	ft_reload_image(vars);
}
