/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:54:00 by grenato-          #+#    #+#             */
/*   Updated: 2022/02/28 18:10:16 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fdf.h>

void	ft_mlx_put_pixel(t_data *data, int x, int y, unsigned int color)
{
	char	*dest;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dest = data->addr + (y * data->line_length + x * \
			(data->bits_per_pixel / 8));
		*(unsigned int *)dest = color;
	}
}

int	ft_key_action(int keycode, t_vars *vars)
{
	unsigned char	c;

	c = (unsigned char)keycode;
	if (keycode == ESC)
		ft_close(vars);
	if (keycode == UP || keycode == DOWN || keycode == RIGHT || keycode == LEFT)
		ft_translate_origin(vars, keycode);
	if (c == 'q' || c == 'w' || c == 'e' || c == 'a' || c == 's' || c == 'd')
		ft_rotate_axis(vars, keycode);
	return (0);
}

void	ft_close(t_vars *vars)
{
	ft_free_map(&vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	vars->mlx = NULL;
	exit(0);
}

void	ft_fdf_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "FDF");
	vars->img = ft_init_image(vars->mlx);
	vars->scale = SCALE_DEFAULT;
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc < 2)
	{
		ft_putstr_fd("Please inform the path to map.\n", 1);
		exit(0);
	}
	vars.map = ft_get_map(argv[1]);
	ft_fdf_init(&vars);
	ft_iso_projection(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_key_hook(vars.win, ft_key_action, &vars);
	mlx_mouse_hook(vars.win, ft_mouse_action, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
