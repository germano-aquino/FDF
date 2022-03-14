/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:04:50 by grenato-          #+#    #+#             */
/*   Updated: 2022/03/14 19:10:40 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

unsigned int	ft_get_proportion(double start, double end, \
					double percent)
{
	if (start == end)
		return (start);
	return ((unsigned int)(start * (1.0 - percent) + percent * end));
}

unsigned int	ft_gradiente(unsigned int color1, \
					unsigned int color2, double percent)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = ft_get_proportion(((color1 >> 16) & 0xFF), \
		((color2 >> 16) & 0xFF), percent);
	g = ft_get_proportion(((color1 >> 8) & 0xFF), \
		((color2 >> 8) & 0xFF), percent);
	b = ft_get_proportion((color1 & 0xFF), (color2 & 0xFF), percent);
	return ((r << 16) | (g << 8) | b);
}

unsigned int	ft_get_color(t_map *map, int z)
{
	double			percent;
	unsigned int	color;

	percent = 1.0 * (z - map->min_z) / (map->max_z - map->min_z);
	color = ft_gradiente(WHITE, PURPLE, percent);
	return (color);
}

unsigned int	ft_get_line_color(t_line *line)
{
	double	percent;
	double	percentx;
	double	percenty;

	percentx = 1.0 * (line->p0.x - line->init.x) / (line->p1.x - line->init.x);
	percenty = 1.0 * (line->p0.y - line->init.y) / (line->p1.y - line->init.y);
	if ((!line->inv && line->p0.x <= line->p0.y) || \
		(line->inv && line->p0.y <= line->p0.x))
		percent = percentx;
	else
		percent = percenty;
	return (ft_gradiente(line->init.color, line->p1.color, percent));
}
