#include <fdf.h>

t_point	ft_get_vector_point(double angle, int norm, t_point orig)
{
	t_point	pt;

	pt.x = (int)floor((double)orig.x + cos(angle) * norm);
	pt.y = (int)floor((double)orig.y + sin(angle) * norm);
	return (pt);
}

void	ft_draw_axis(t_vars	*vars)
{
	t_point	origin;
	t_point	p_axis;

	int		scale;

	scale = 10 * vars->scale;
	origin.x = ISO_ORIGIN_X;
	origin.y = ISO_ORIGIN_Y;
	//get x_axis 30º
	p_axis = ft_get_vector_point(ISO_X_ANGLE, scale, origin);
	ft_draw_line(origin.x, origin.y, p_axis.x, p_axis.y, &vars->img);
	//get y_axis 150º
	p_axis = ft_get_vector_point(ISO_Y_ANGLE, scale, origin);
	ft_draw_line(origin.x, origin.y, p_axis.x, p_axis.y, &vars->img);
	//get z_axis 270º
	p_axis = ft_get_vector_point(ISO_Z_ANGLE, scale, origin);
	ft_draw_line(origin.x, origin.y, p_axis.x, p_axis.y, &vars->img);
}

void	ft_iso_projection(t_vars *vars)
{
	ft_draw_axis(vars);
}