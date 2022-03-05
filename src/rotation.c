/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:23:00 by grenato-          #+#    #+#             */
/*   Updated: 2022/03/04 21:51:55 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_init_quaternion(t_quaternion *q, t_quaternion *conj, \
		int up_or_down, double *vec)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		q->vec[i] = vec[i] * sin((-2 * (up_or_down % 2) + 1) * DELTA / 2) \
			/ ft_get_norm(vec);
		conj->vec[i] = -q->vec[i];
	}
	q->re = cos((-2 * (up_or_down % 2) + 1) * DELTA / 2);
	conj->re = q->re;
}

double	**ft_rotate_around_vector(double **base, double *vec, int up_or_down)
{
	t_quaternion	q;
	int				ind[2];
	double			**new_base;
	t_quaternion	p;
	t_quaternion	conj_q;

	ft_init_quaternion(&q, &conj_q, up_or_down, vec);
	new_base = ft_init_base();
	ind[0] = -1;
	while (++ind[0] < 3)
	{
		p.re = 0;
		ind[1] = -1;
		while (++ind[1] < 3)
			p.vec[ind[1]] = base[ind[0]][ind[1]];
		p = ft_quaternion_mult(q, p);
		p = ft_quaternion_mult(p, conj_q);
		ind[1] = -1;
		while (++ind[1] < 3)
			new_base[ind[0]][ind[1]] = p.vec[ind[1]];
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
