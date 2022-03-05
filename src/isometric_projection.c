/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 00:06:00 by grenato-          #+#    #+#             */
/*   Updated: 2022/03/03 20:20:13 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_point	ft_get_vector_point(double angle, int norm, t_point orig)
{
	t_point	pt;

	pt.x = (int)floor((double)orig.x + cos(angle) * norm);
	pt.y = (int)floor((double)orig.y + sin(angle) * norm);
	return (pt);
}

t_point	ft_get_iso_point(t_vars *vars, t_point pt)
{
	t_point	new_point;
	double	*axis_angle;
	int		scale;

	scale = vars->scale;
	axis_angle = ft_get_axis_angle(&vars->map);
	new_point = ft_get_vector_point(axis_angle[0], pt.x * scale, \
		vars->map.origin);
	new_point = ft_get_vector_point(axis_angle[1], pt.y * scale, new_point);
	new_point = ft_get_vector_point(axis_angle[2], pt.z * scale / 4, new_point);
	new_point.z = pt.z;
	new_point.color = pt.color;
	free(axis_angle);
	axis_angle = NULL;
	return (new_point);
}

void	ft_get_iso_grid(t_vars *vars)
{
	int		x;
	int		y;
	t_point	map_pt;

	y = 0;
	while (y < vars->map.height)
	{
		x = 0;
		while (x < vars->map.width)
		{
			map_pt.color = vars->map.grid[y][x].color;
			map_pt.x = x;
			map_pt.y = y;
			map_pt.z = vars->map.grid[y][x].z;
			vars->map.grid[y][x] = ft_get_iso_point(vars, map_pt);
			x++;
		}
		y++;
	}
}

void	ft_draw_iso_map(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	while (++y < vars->map.height)
	{
		x = -1;
		while (++x < vars->map.width - 1)
			ft_draw_line(vars->map.grid[y][x], vars->map.grid[y][x + 1] \
			, &vars->img);
	}
	x = -1;
	while (++x < vars->map.width)
	{
		y = -1;
		while (++y < vars->map.height - 1)
			ft_draw_line(vars->map.grid[y][x], vars->map.grid[y + 1][x] \
			, &vars->img);
	}
}

void	ft_iso_projection(t_vars *vars)
{
	ft_get_iso_grid(vars);
	ft_draw_iso_map(vars);
}
