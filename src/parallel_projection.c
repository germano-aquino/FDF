/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_projection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:49:28 by grenato-          #+#    #+#             */
/*   Updated: 2022/03/14 19:03:13 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_para_z_projection(t_map *map, int scale, t_data *img)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width - 1)
		{
			map->grid[j][i].x = map->origin.x + scale * (i);
			map->grid[j][i].y = map->origin.y + scale * (j);
			map->grid[j][i + 1].x = map->origin.x + scale * (i + 1);
			map->grid[j][i + 1].y = map->origin.y + scale * (j);
			ft_draw_line(map->grid[j][i], map->grid[j][i + 1], img);
		}
	}
	i = -1;
	while (++i < map->width)
	{
		j = -1;
		while (++j < map->height - 1)
		{
			ft_draw_line(map->grid[j][i], map->grid[j + 1][i], img);
		}
	}
}

void	ft_para_y_projection(t_map *map, int scale, t_data *img)
{
	int		i;
	int		j;
	t_point	**grid;

	grid = map->grid;
	j = -1;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width - 1)
		{
			grid[j][i].x = map->origin.x + scale * (i);
			grid[j][i].y = map->origin.y - scale * (grid[j][i].z);
			grid[j][i + 1].x = map->origin.x + scale * (i + 1);
			grid[j][i + 1].y = map->origin.y - scale * (grid[j][i + 1].z);
			ft_draw_line(grid[j][i], grid[j][i + 1], img);
		}
	}
	i = -1;
	while (++i < map->width)
	{
		j = -1;
		while (++j < map->height - 1)
			ft_draw_line(map->grid[j][i], map->grid[j + 1][i], img);
	}
}

void	ft_para_x_projection(t_map *map, int scale, t_data *img)
{
	int		i;
	int		j;
	t_point	**grid;

	grid = map->grid;
	j = -1;
	while (++j < map->height)
	{
		i = -1;
		while (++i < map->width - 1)
		{
			grid[j][i].x = map->origin.x + scale * (j);
			grid[j][i].y = map->origin.y - scale * (grid[j][i].z);
			grid[j][i + 1].x = map->origin.x + scale * (j + 1);
			grid[j][i + 1].y = map->origin.y - scale * (map->grid[j][i + 1].z);
			ft_draw_line(map->grid[j][i], map->grid[j][i + 1], img);
		}
	}
	i = -1;
	while (++i < map->width)
	{
		j = -1;
		while (++j < map->height - 1)
			ft_draw_line(map->grid[j][i], map->grid[j + 1][i], img);
	}
}
