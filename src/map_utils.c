/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:39:18 by grenato-          #+#    #+#             */
/*   Updated: 2022/03/18 16:52:25 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

double	ft_get_angle_between_vectors(double *proj_base, double u_vec[3])
{
	double	alpha;
	double	*w;
	double	n_vec[3];
	double	cosin;
	int		i;

	i = -1;
	while (++i < 3)
		n_vec[i] = 1;
	cosin = floor(10000 * ft_dot_product(proj_base, u_vec)) * 1.0 / \
		(ceil(ft_get_norm(proj_base) * 10000));
	alpha = acos(cosin);
	w = ft_cross_product(u_vec, proj_base);
	if (ft_dot_product(w, n_vec) < 0)
		alpha = 2 * M_PI - alpha;
	free(w);
	w = NULL;
	return (alpha);
}

double	**ft_init_base(void)
{
	double	**base;
	int		i;

	base = (double **)malloc(sizeof(double *) * 4);
	if (base == NULL)
		perror("Error");
	i = -1;
	while (++i < 3)
	{
		base[i] = (double *)malloc(sizeof(double) * 3);
		if (base[i] == NULL)
			perror("Error");
	}
	base[i] = NULL;
	return (base);
}

double	**ft_init_origin(t_map *map)
{
	int		i;
	int		j;
	double	**vec_base;

	vec_base = ft_init_base();
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			if (i == j)
				vec_base[i][j] = 1;
			else
				vec_base[i][j] = 0;
		}
	}
	map->origin.x = ISO_ORIGIN_X;
	map->origin.y = ISO_ORIGIN_Y;
	return (vec_base);
}

double	*ft_get_axis_angle(t_map *map)
{
	double	*axis_angle;
	double	u_vec[3];
	double	**proj_base;

	u_vec[0] = sqrt(2) / 2;
	u_vec[1] = -sqrt(2) / 2;
	u_vec[2] = 0;
	axis_angle = (double *)malloc(sizeof(double) * 3);
	if (axis_angle == NULL)
		perror("Error");
	proj_base = ft_project_axis_onto_plane(map->vec_base);
	axis_angle[0] = ft_get_angle_between_vectors(proj_base[0], u_vec);
	axis_angle[1] = ft_get_angle_between_vectors(proj_base[1], u_vec);
	axis_angle[2] = ft_get_angle_between_vectors(proj_base[2], u_vec);
	ft_free_2d_double_ptr(&proj_base);
	return (axis_angle);
}

double	**ft_project_axis_onto_plane(double **base)
{
	int		i;
	int		j;
	double	**proj_base;
	double	n_vec[3];

	proj_base = ft_init_base();
	i = -1;
	while (++i < 3)
		n_vec[i] = 1;
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			proj_base[i][j] = base[i][j] - \
				(ft_dot_product(base[i], n_vec) * n_vec[j]) / 3;
		}
	}
	return (proj_base);
}
