/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_projection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:49:28 by grenato-          #+#    #+#             */
/*   Updated: 2022/03/18 16:02:15 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_draw_checkered(int height, int width, t_point **grid, t_data *img)
{
	int	i;
	int	j;

	j = -1;
	while (++j < height)
	{
		i = -1;
		while (++i < width - 1)
		{
			ft_draw_line(grid[j][i], grid[j][i + 1], img);
		}
	}
	i = -1;
	while (++i < width)
	{
		j = -1;
		while (++j < height - 1)
		{
			ft_draw_line(grid[j][i], grid[j + 1][i], img);
		}
	}
}

void	ft_para_z_projection(t_map *map, int scale, t_data *img)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			map->grid[j][i].x = map->origin.x + scale * (i);
			map->grid[j][i].y = map->origin.y + scale * (j);
		}
	}
	ft_draw_checkered(map->height, map->width, map->grid, img);
}

void	ft_para_y_projection(t_map *map, int scale, t_data *img)
{
	int		i;
	int		j;
	t_point	**grid;

	grid = map->grid;
	j = -1;
	map->origin.y = 300;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			grid[j][i].x = map->origin.x + scale * (i);
			grid[j][i].y = map->origin.y - scale * (grid[j][i].z);
		}
	}
	ft_draw_checkered(map->height, map->width, map->grid, img);
}

void	ft_para_x_projection(t_map *map, int scale, t_data *img)
{
	int		i;
	int		j;
	t_point	**grid;

	grid = map->grid;
	j = -1;
	map->origin.y = 300;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width)
		{
			grid[j][i].x = map->origin.x + scale * (j);
			grid[j][i].y = map->origin.y - scale * (grid[j][i].z);
		}
	}
	ft_draw_checkered(map->height, map->width, map->grid, img);
}
