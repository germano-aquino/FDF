/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:09:13 by grenato-          #+#    #+#             */
/*   Updated: 2022/02/23 00:02:42 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdio.h>

void	ft_get_map_width_and_height(t_map *map, char **line, int fd)
{
	char	*temp;
	int		already_counted;

	already_counted = 0;
	temp = *line;
	while (*temp != '\n')
	{
		if (*temp != ' ' && !already_counted)
		{
			already_counted = 1;
			map->width++;
		}
		if (already_counted && *temp == ' ')
			already_counted = 0;
		temp++;
	}
	temp = NULL;
	while (*line != NULL)
	{
		map->height++;
		free(*line);
		*line = get_next_line(fd);
	}
}

void	ft_map_init(t_map *map, int fd)
{
	char	*line;
	int		i;

	map->height = 0;
	map->width = 0;
	map->grid = NULL;
	line = get_next_line(fd);
	ft_get_map_width_and_height(map, &line, fd);
	map->grid = (t_point **)malloc(sizeof(t_point *) * map->height);
	if (map->grid == NULL)
		perror("Error");
	i = 0;
	while (i < map->height)
	{
		*(map->grid + i) = (t_point *)malloc(sizeof(t_point) * map->width);
		if (*(map->grid + i) == NULL)
			perror("Error");
		i++;
	}
}

void	ft_parse_line_to_map(char *line, t_map *map, int y)
{
	char	**split;
	char	**value_color;
	int		x;

	split = ft_split(line, ' ');
	x = 0;
	while (*(split + x) != NULL)
	{
		if (**(split + x) != '\n')
		{
			value_color = ft_split(*(split + x), ',');
			(*(*(map->grid + y) + x)).z = ft_atoi(*value_color);
			if (*(value_color + 1) == NULL)
				(*(*(map->grid + y) + x)).color = WHITE;
			else
				(*(*(map->grid + y) + x)).color = \
					(unsigned int)ft_atoi(*(value_color + 1));
			ft_free_2d_ptr(&value_color);
		}
		x++;
	}
	ft_free_2d_ptr(&split);
}

void	ft_free_map(t_map *map)
{
	int		i;
	t_point	*temp;

	i = 0;
	while (i < map->height)
	{
		temp = *(map->grid + i);
		free(temp);
		temp = NULL;
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

void	ft_get_map(t_map *map, char *str_to_map)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(str_to_map, O_RDONLY);
	if (fd == -1)
		perror("Error");
	ft_map_init(map, fd);
	close(fd);
	fd = open(str_to_map, O_RDONLY);
	if (fd == -1 || fd == 0)
		perror("Error");
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		ft_parse_line_to_map(line, map, i);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}
