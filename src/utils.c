/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:20:56 by grenato-          #+#    #+#             */
/*   Updated: 2022/02/24 17:39:55 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdio.h>

void	ft_free_2d_ptr(char ***ptr)
{
	char	**temp;
	int		i;

	temp = *ptr;
	i = 0;
	while (*temp != NULL)
	{
		free(*temp);
		*temp = NULL;
		i++;
		temp = (*ptr + i);
	}
	free(*ptr);
	*ptr = NULL;
}

void	ft_print_map(t_vars *vars)
{
	int	i;
	int	j;

	for (j = 0; j < vars->map.height; j++)
	{
		for (i = 0; i < vars->map.width; i++)
		{
			printf("%d ", vars->map.grid[j][i].z);
		}
		printf("\n");
	}
}

int		ft_open_map_file(char *path_to_map)
{
	int	fd;

	fd = open(path_to_map, O_RDONLY);
	if (fd == 0 || fd == -1)
		perror("Error");
	return (fd);
}

double	*ft_init_axis_angle()
{
	double	*axis_angle;
	
	axis_angle = (double *)malloc(sizeof(double) * 3);
	if (axis_angle == NULL)
		perror("Error");
	axis_angle[0] = ISO_X_ANGLE;
	axis_angle[1] = ISO_Y_ANGLE;
	axis_angle[2] = ISO_Z_ANGLE;
	return (axis_angle);
}

void	ft_swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

t_data	ft_init_image(void *mlx)
{
	t_data	img;
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.bits_per_pixel = 32;
	img.line_length = WIDTH;
	img.addr = mlx_get_data_addr(img.img, \
		&img.bits_per_pixel, &img.line_length, &img.endian);
	return(img);
}