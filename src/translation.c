#include <fdf.h>
#include <stdio.h>

void	ft_reload_image(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img = ft_init_image(vars->mlx);
	ft_iso_projection(vars);
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	ft_translate_origin(t_vars *vars, int direction)
{
	int step;
	t_point	*origin;

	origin = &vars->map.origin;
	step = 10;
	if (direction == UP)
		origin->y -= step;
	if (direction == DOWN)
		origin->y += step;
	if (direction == RIGHT)
		origin->x += step;
	if (direction == LEFT)
		origin->x -= step;
	ft_reload_image(vars);
}
