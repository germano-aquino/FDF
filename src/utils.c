/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:20:56 by grenato-          #+#    #+#             */
/*   Updated: 2022/03/23 20:23:32 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdio.h>

void	ft_swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

t_data	ft_init_image(void *mlx)
{
	t_data	img;

	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.bits_per_pixel = 32;
	img.line_length = WIDTH;
	img.addr = mlx_get_data_addr(img.img, \
		&img.bits_per_pixel, &img.line_length, &img.endian);
	return (img);
}

int	ft_open_map_file(char *path_to_map)
{
	int	fd;

	fd = open(path_to_map, O_RDONLY);
	if (fd == 0 || fd == -1)
	{
		perror("Error");
		exit(0);
	}
	return (fd);
}

void	ft_store_min_and_max_z(t_map *map, int z)
{
	if (map->min_z > z)
		map->min_z = z;
	if (map->max_z < z)
		map->max_z = z;
}
