/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:54:00 by grenato-          #+#    #+#             */
/*   Updated: 2022/02/21 23:24:11 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fdf.h>

void ft_mlx_put_pixel(t_data *data, int x, int y, unsigned int color)
{
	char	*dest;

	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dest = color;
	}
}

int ft_close(int keycode, t_vars *vars)
{
	if ( (unsigned char)keycode == ESC)
	{
		ft_free_map(&vars->map);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_image(vars->mlx, vars->img.img);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		vars->mlx = NULL;
		exit(0);
	}
	return (0);
}

void	ft_fdf_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "FDF");
	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img.bits_per_pixel = 32;
	vars->img.line_length = WIDTH;
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	vars->scale = SCALE_DEFAULT;
}

int main (int argc, char *argv[])
{
	t_vars	vars;

	if (argc < 2)
	{
		ft_putstr_fd("Please inform the path to map.\n", 1);
		exit(0);
	}
	ft_get_map(&vars.map, argv[1]);
	ft_fdf_init(&vars);
/* 	ft_draw_line(0, 0, WIDTH, HEIGHT, &vars.img);
	ft_draw_line(0, HEIGHT, WIDTH, 0, &vars.img);
	ft_draw_line(0, HEIGHT / 2, WIDTH, HEIGHT / 2, &vars.img);
	ft_draw_line(WIDTH / 2, 0, WIDTH / 2, HEIGHT, &vars.img); */
	ft_iso_projection(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_key_hook(vars.win, ft_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}