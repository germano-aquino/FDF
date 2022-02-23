/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 00:31:15 by grenato-          #+#    #+#             */
/*   Updated: 2022/02/23 00:42:54 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_line	ft_init_line(t_point p0, t_point p1)
{
	t_line	line;

	line.p0 = p0;
	line.p1 = p1;
	line.dx = (p1.x - p0.x) << 1;
	line.dy = (p1.y - p0.y) << 1;
	if (line.dx < 0)
	{
		line.dx = -line.dx;
		line.stepx = -1;
	}
	else
		line.stepx = 1;
	if (line.dy < 0)
	{
		line.dy = -line.dy;
		line.stepy = -1;
	}
	else
		line.stepy = 1;
	line.inv = 0;
	return (line);
}

void	ft_invert_x_and_y_line(t_line *line)
{
	ft_swap(&(line->p0.x), &(line->p0.y));
	ft_swap(&(line->p1.x), &(line->p1.y));
	ft_swap(&(line->stepx), &(line->stepy));
	ft_swap(&(line->dx), &(line->dy));
}

void	ft_put_line_pixel(t_data *img, t_line *line)
{
	if (!line->inv)
		ft_mlx_put_pixel(img, line->p0.x, line->p0.y, WHITE);
	else
		ft_mlx_put_pixel(img, line->p0.y, line->p0.x, WHITE);
}

void	ft_line_bresenham(t_line *line, t_data *img)
{
	int	fraction;

	if (line->dx < line->dy)
	{
		line->inv = 1;
		ft_invert_x_and_y_line(line);
	}
	fraction = line->dy - (line->dx >> 1);
	ft_put_line_pixel(img, line);
	while (line->p0.x != line->p1.x)
	{
		if (fraction >= 0)
		{
			line->p0.y += line->stepy;
			fraction -= line->dx;
		}
		line->p0.x += line->stepx;
		fraction += line->dy;
		ft_put_line_pixel(img, line);
	}
}

void	ft_draw_line(t_point p0, t_point p1, t_data *img)
{
	t_line	line;

	line = ft_init_line(p0, p1);
	ft_line_bresenham(&line, img);
}
