/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:23:00 by grenato-          #+#    #+#             */
/*   Updated: 2022/03/01 22:42:10 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_init_quaternion(t_quaternion *q, int up_or_down, \
			double *s, double *vec)
{
	int	i;

	i = -1;
	*s = 0;
	while (++i < 3)
	{
		q->vec[i] = vec[i] * sin((-2 * (up_or_down % 2) + 1) * DELTA / 2);
		*s += q->vec[i] * q->vec[i];
	}
	q->real = cos((-2 * (up_or_down % 2) + 1) * DELTA / 2);
	*s += q->real * q->real;
	*s = 1 / *s;
}

double	**ft_rotate_around_vector(double **base, double *vec, int up_or_down)
{
	t_quaternion	q;
	int				i;
	double			**new_base;
	double			s;

	ft_init_quaternion(&q, up_or_down, &s, vec);
	new_base = ft_init_base();
	i = -1;
	while (++i < 3)
	{
		new_base[i][0] = (1 - 2 * s * (q.vec[1] * q.vec[1] + \
			q.vec[2] * q.vec[2])) * base[i][0] + \
			2 * s * (q.vec[0] * q.vec[1] - q.real * q.vec[2]) * base[i][1] \
			+ 2 * s * (q.vec[0] * q.vec[2] + q.vec[1] * q.real) * base[i][2];
		new_base[i][1] = 2 * s * (q.vec[0] * q.vec[1] + q.vec[2] * q.real) \
			* base[i][0] + (1 - 2 * s * (q.vec[0] * q.vec[0] + q.vec[2] \
			* q.vec[2])) * base[i][1] + 2 * s * (q.vec[1] * q.vec[2] - \
			q.vec[0] * q.real) * base[i][2];
		new_base[i][2] = 2 * s * (q.vec[0] * q.vec[2] + q.vec[1] * q.real) \
			* base[i][0] + 2 * s * (q.vec[1] * q.vec[2] - q.vec[0] * q.real) \
			* base[i][1] + (1 - 2 * s * (q.vec[0] * q.vec[0] + q.vec[1] \
			* q.vec[1])) * base[i][2];
	}
	return (new_base);
}

void	ft_rotate_axis(t_vars *vars, int keycode)
{
	t_map			*map;
	double			**old_base;

	map = &vars->map;
	old_base = map->vec_base;
	if (keycode == 'w')
		map->vec_base = ft_rotate_around_vector(old_base, old_base[0], 0);
	if (keycode == 's')
		map->vec_base = ft_rotate_around_vector(old_base, old_base[0], 1);
	if (keycode == 'a')
		map->vec_base = ft_rotate_around_vector(old_base, old_base[2], 0);
	if (keycode == 'd')
		map->vec_base = ft_rotate_around_vector(old_base, old_base[2], 1);
	if (keycode == 'q')
		map->vec_base = ft_rotate_around_vector(old_base, old_base[1], 0);
	if (keycode == 'e')
		map->vec_base = ft_rotate_around_vector(old_base, old_base[1], 1);
	ft_free_2d_double_ptr(&old_base);
	ft_reload_image(vars);
}
