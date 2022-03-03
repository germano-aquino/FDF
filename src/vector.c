/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 22:42:12 by grenato-          #+#    #+#             */
/*   Updated: 2022/03/01 22:42:21 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

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
	while (++i < 3)
	{
		product += vec1[i] * vec2[i];
	}
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
