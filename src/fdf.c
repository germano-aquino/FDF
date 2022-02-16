/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:54:00 by grenato-          #+#    #+#             */
/*   Updated: 2022/02/16 17:35:57 by grenato-         ###   ########.fr       */
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

int ft_close(int keycode, t_map *map)
{
	if ( (unsigned char)keycode == ESC)
	{
		ft_free_map(map);
		exit(0);
	}
	return (0);
}

void	ft_fdf_init(t_env *env, t_data *img)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "FDF");
	img->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	img->bits_per_pixel = 32;
	img->line_length = WIDTH;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);

}

int main (int argc, char *argv[])
{
	t_env	env;
	t_data	img;
	t_map	map;

	if (argc < 2)
	{
		ft_putstr_fd("Please inform the path to map.\n", 1);
		exit(0);
	}
	ft_get_map(&map, argv[1]);
	ft_fdf_init(&env, &img);
	ft_draw_line(0, 0, WIDTH, HEIGHT, &img);
	ft_draw_line(0, HEIGHT, WIDTH, 0, &img);
	ft_draw_line(0, HEIGHT / 2, WIDTH, HEIGHT / 2, &img);
	ft_draw_line(WIDTH / 2, 0, WIDTH / 2, HEIGHT, &img);
	mlx_put_image_to_window(env.mlx, env.win, img.img, 0, 0);
	mlx_key_hook(env.win, ft_close, &map);
	mlx_loop(env.mlx);
	return (0);
}