#include <fdf.h>


double	**ft_rotate_around_vector(double **base, double *vec, int up_or_down)
{
	t_quaternion	q;
	int				i;
	double			**new_base;
	double			s;
	int				j;

	i = -1;
	s = 0;
	while(++i < 3)
	{
		q.vec[i] = vec[i] * sin((-2 * (up_or_down % 2) + 1) * DELTA / 2);
		s += q.vec[i] * q.vec[i];
	}
	q.real = cos((-2 * (up_or_down % 2) + 1) * DELTA / 2);
	s += q.real * q.real;
	s = 1 / s;
	new_base = (double **)malloc(sizeof(double *) * 4);
	if (new_base == NULL)
		perror("Error");
	i = -1;
	while (++i < 3)
	{
		new_base[i] = (double *)malloc(sizeof(double) * 3);
		if (new_base[i] == NULL)
			perror("Error");
	}
	new_base[i] = NULL;
	i = -1;
	printf("s: %lf\n ijk: %lf %lf %lf\nreal: %lf\n base: %lf %lf %lf\n\n",s, q.vec[0], q.vec[1], q.vec[2], q.real, vec[0], vec[1], vec[2]);
	while (++i < 3)
	{
		new_base[i][0] = (1 - 2 * s * (q.vec[1] * q.vec[1] + \
			q.vec[2] * q.vec[2])) * base[i][0] + \
			2 * s * (q.vec[0] * q.vec[1] - q.real * q.vec[2]) * base[i][1]\
			+ 2 * s * (q.vec[0] * q.vec[2] + q.vec[1] * q.real) * base[i][2];
		new_base[i][1] = 2 * s * (q.vec[0] * q.vec[1] + q.vec[2] * q.real) * base[i][0] + \
			(1 - 2 * s * (q.vec[0] * q.vec[0] + q.vec[2] * q.vec[2])) * base[i][1]\
			+ 2 * s * (q.vec[1] * q.vec[2] - q.vec[0] * q.real) * base[i][2];
		new_base[i][2] = 2 * s * (q.vec[0] * q.vec[2] + q.vec[1] * q.real) * base[i][0]\
			+ 2 * s * (q.vec[1] * q.vec[2] - q.vec[0] * q.real) * base[i][1] \
			+ (1 - 2 * s * (q.vec[0] * q.vec[0] + q.vec[1] * q.vec[1])) * base[i][2];
	}
	j = -1;
	while (++j < 3)
	{
		i = -1;
		while(++i < 3) printf("%lf ",new_base[i][j]);
		printf("\n");
	}
	printf("\n");
	return (new_base);
}

void	ft_rotate_axis(t_vars *vars, int keycode)
{
	/*w - s rotation over x-axis
	  a - d rotation over z-axis
	  q - e rotation over y-axis*/
	t_map			*map;
	double			**temp;
	int i;
	int j;

	map = &vars->map;
	temp = map->vec_base;
	j = -1;
	while (++j < 3)
	{
		i = -1;
		while(++i < 3) printf("%lf ",map->vec_base[i][j]);
		printf("\n");
	}
	printf("\n");
	if (keycode == 'w')
		map->vec_base = ft_rotate_around_vector(map->vec_base, map->vec_base[0], 0);
	if (keycode == 's')
		map->vec_base = ft_rotate_around_vector(map->vec_base, map->vec_base[0], 1);
	if (keycode == 'a')
		map->vec_base = ft_rotate_around_vector(map->vec_base, map->vec_base[2], 0);
	if (keycode == 'd')
		map->vec_base = ft_rotate_around_vector(map->vec_base, map->vec_base[2], 1);
	if (keycode == 'q')
		map->vec_base = ft_rotate_around_vector(map->vec_base, map->vec_base[1], 0);
	if (keycode == 'e')
		map->vec_base = ft_rotate_around_vector(map->vec_base, map->vec_base[1], 1);
	ft_free_2d_double_ptr(&temp);
	ft_reload_image(vars);
}

double	ft_get_norm(double *vec)
{
	double	norm;
	int		i;

	norm = 0;
	i = -1;
	while (++i < 3)
		norm += vec[i] * vec[i];
	norm = sqrt(norm);
	return (norm);
}

double	ft_dot_product(double vec1[3], double vec2[3])
{
	int		i;
	double	product;

	product = 0;
	i = -1;
	while (++i < 3) \
		product += vec1[i] * vec2[i];
	return (product);
}

double	*ft_cross_product(double *vec1, double *vec2)
{
	double	*cross;

	cross = (double *)malloc(sizeof(double) * 3);
	if (cross == NULL)
		perror("Error");
	cross[0] = vec1[1] * vec2[2] - vec2[1] * vec1[2];
	cross[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
	cross[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
	return (cross);
}
