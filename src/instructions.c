/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 00:50:20 by grenato-          #+#    #+#             */
/*   Updated: 2022/03/14 18:31:24 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_rectangle	ft_get_rectangle(int x1, int y1, int x2, int y2)
{
	t_rectangle	rect;

	if (x1 > x2)
		ft_swap(&x1, &x2);
	if (y1 > y2)
		ft_swap(&y1, &y2);
	rect.p0.x = x1;
	rect.p0.y = y1;
	rect.p1.x = x2;
	rect.p1.y = y2;
	rect.width = x2 - x1;
	rect.height = y2 - y1;
	return (rect);
}

void	ft_draw_rectangle(t_vars *vars, t_rectangle rect, \
						unsigned int color)
{
	int	i;
	int	j;

	j = -1;
	while (++j < rect.height)
	{
		i = -1;
		while (++i < rect.width)
			ft_mlx_put_pixel(&vars->img, rect.p0.x + i, rect.p0.y + j, color);
	}
}

void	ft_draw_boxes(t_vars *vars)
{
	ft_draw_rectangle(vars, ft_get_rectangle(0, 0, WIDTH, HEIGHT), GREY6);
	ft_draw_rectangle(vars, ft_get_rectangle(100, 25, 860, 75), GREEN3);
	ft_draw_rectangle(vars, ft_get_rectangle(100, 100, 340, 200), GREY4);
	ft_draw_rectangle(vars, ft_get_rectangle(360, 100, 600, 200), GREY4);
	ft_draw_rectangle(vars, ft_get_rectangle(620, 100, 860, 200), GREY4);
	ft_draw_rectangle(vars, ft_get_rectangle(100, 220, 340, 320), GREY4);
	ft_draw_rectangle(vars, ft_get_rectangle(360, 220, 600, 340), GREY4);
	ft_draw_rectangle(vars, ft_get_rectangle(620, 220, 860, 320), GREY4);
	ft_draw_rectangle(vars, ft_get_rectangle(100, 340, 360, 440), GREY4);
	ft_draw_rectangle(vars, ft_get_rectangle(360, 340, 620, 440), GREY4);
	ft_draw_rectangle(vars, ft_get_rectangle(620, 340, 860, 440), GREY4);
	ft_draw_rectangle(vars, ft_get_rectangle(100, 465, 860, 515), PINK3);
}

void	ft_write_instructions(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 420, 50, WHITE, \
		"Press TAB to continue");
	mlx_string_put(vars->mlx, vars->win, 340, 490, WHITE, \
		"Press F1 to show instructions or ESC to escape");
	mlx_string_put(vars->mlx, vars->win, 160, 120, ORANGE, \
		"Rotate over X axis");
	mlx_string_put(vars->mlx, vars->win, 170, 160, ORANGE, \
		"W / S <=> + / -");
	mlx_string_put(vars->mlx, vars->win, 420, 120, ORANGE, \
		"Rotate over Y axis");
	mlx_string_put(vars->mlx, vars->win, 430, 160, ORANGE, \
		"Q / E <=> + / -");
	mlx_string_put(vars->mlx, vars->win, 680, 120, ORANGE, \
		"Rotate over Z axis");
	mlx_string_put(vars->mlx, vars->win, 690, 160, ORANGE, \
		"A / D <=> + / -");
	mlx_string_put(vars->mlx, vars->win, 200, 240, ORANGE, \
		"Move");
	mlx_string_put(vars->mlx, vars->win, 160, 270, ORANGE, \
		"Press the arrows to");
	mlx_string_put(vars->mlx, vars->win, 170, 290, ORANGE, \
		"Translate the map");
	mlx_string_put(vars->mlx, vars->win, 440, 240, ORANGE, \
		"Projections");
}

void	ft_show_instructions(t_vars *vars)
{
	ft_draw_boxes(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	ft_write_instructions(vars);
	mlx_string_put(vars->mlx, vars->win, 430, 270, ORANGE, \
		"Press \"I\" to show");
	mlx_string_put(vars->mlx, vars->win, 420, 290, ORANGE, \
		"Isometric Projection");
	mlx_string_put(vars->mlx, vars->win, 160, 380, ORANGE, \
		"Press \"X\" to show");
	mlx_string_put(vars->mlx, vars->win, 150, 400, ORANGE, \
		"X Parallel Projection");
	mlx_string_put(vars->mlx, vars->win, 420, 380, ORANGE, \
		"Press \"Y\" to show");
	mlx_string_put(vars->mlx, vars->win, 410, 400, ORANGE, \
		"Y Parallel Projection");
	mlx_string_put(vars->mlx, vars->win, 680, 380, ORANGE, \
		"Press \"Z\" to show");
	mlx_string_put(vars->mlx, vars->win, 670, 400, ORANGE, \
		"Z Parallel Projection");
	mlx_string_put(vars->mlx, vars->win, 720, 240, ORANGE, \
		"Scale");
	mlx_string_put(vars->mlx, vars->win, 670, 270, ORANGE, \
		"Scroll UP / Scroll DOWN");
	mlx_string_put(vars->mlx, vars->win, 680, 290, ORANGE, \
		"ZOOM In / ZOOM Out");
}
