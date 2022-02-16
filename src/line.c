#include <fdf.h>

void	ft_init_line(t_line *line, int x0, int y0, int x1, int y1)
{
	line->p0.x = x0;
	line->p0.y = y0;
	line->p1.x = x1;
	line->p1.y = y1;
	line->dx = (x1 - x0) << 1;
	line->dy = (y1 - y0) << 1;
	if (line->dx < 0)
	{
		line->dx = - line->dx;
		line->stepx = -1;
	}
	else
		line->stepx = 1;
	if (line->dy < 0)
	{
		line->dy = - line->dy;
		line->stepy = -1;
	}
	else
		line->stepy = 1;
	line->inv = 0;
}

void	ft_swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	ft_invert_x_and_y_line(t_line *line)
{
	ft_swap(&(line->p0.x), &(line->p0.y));
	ft_swap(&(line->p1.x), &(line->p1.y));
	ft_swap(&(line->stepx), &(line->stepy));
	ft_swap(&(line->dx), &(line->dy));
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
	if (!line->inv)
		ft_mlx_put_pixel(img, line->p0.x, line->p0.y, WHITE);
	else
		ft_mlx_put_pixel(img, line->p0.y, line->p0.x, WHITE);
	while (line->p0.x != line->p1.x)
	{
		if (fraction >= 0)
		{
			line->p0.y += line->stepy;
			fraction -= line->dx;
		}
		line->p0.x += line->stepx;
		fraction += line->dy;
		if (!line->inv)
			ft_mlx_put_pixel(img, line->p0.x, line->p0.y, WHITE);
		else
			ft_mlx_put_pixel(img, line->p0.y, line->p0.x, WHITE);
	}
	
}

void	ft_draw_line(int x0, int y0, int x1, int y1, t_data *img)
{
	t_line	line;

	ft_init_line(&line, x0, y0, x1, y1);
	ft_line_bresenham(&line, img);
}