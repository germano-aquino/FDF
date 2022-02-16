/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grenato- <grenato-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:31:45 by grenato-          #+#    #+#             */
/*   Updated: 2022/02/14 18:47:26 by grenato-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

void	ft_free(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int	ft_read_from_fd(t_buffer *buff_add, int fd)
{
	int	sz;

	sz = read(fd, (*buff_add).begin, BUFFER_SIZE);
	if (!sz || sz == -1)
		return (0);
	(*buff_add).begin[sz] = '\0';
	(*buff_add).end = (*buff_add).begin;
	return (1);
}

char	*ft_line_alloc(char **ptr, int *size, int first_allocation)
{
	char	*new;
	int		index;

	*size += BUFFER_SIZE;
	new = (char *) malloc(sizeof(char) * *size);
	if (!new)
		return (NULL);
	index = 0;
	new[index] = '\0';
	if (!first_allocation)
	{
		while (index < *size - BUFFER_SIZE - 1)
		{
			new[index] = *(*ptr + index);
			index++;
		}
		free(*ptr);
		*ptr = NULL;
	}
	return (new);
}

char	*ft_get_line(t_buffer *buff_add, int fd)
{
	char	*line;
	int		line_size;
	int		index;
	int		line_not_end;

	line_size = 1;
	line = ft_line_alloc(&line, &line_size, 1);
	index = 0;
	line_not_end = 1;
	while (line_not_end)
	{
		if (*buff_add->end == '\0' && !ft_read_from_fd(buff_add, fd))
			return (line);
		line[index] = *buff_add->end;
		if (*buff_add->end == '\n')
			line_not_end = 0;
		(*buff_add).end++;
		index++;
		if (index % BUFFER_SIZE == 0)
			line = ft_line_alloc(&line, &line_size, 0);
		line[index] = '\0';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_buffer	buff[MAX_FD];
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 256)
		return (NULL);
	if ((buff[fd]).begin == NULL)
	{
		(buff[fd]).begin = (char *) malloc(sizeof(char) * ((BUFFER_SIZE + 1)));
		(buff[fd]).end = (buff[fd]).begin;
		if (!(buff[fd]).begin || !ft_read_from_fd(&(buff[fd]), fd))
		{
			ft_free(&(buff[fd]).begin);
			(buff[fd]).end = NULL;
			return (NULL);
		}
	}
	line = ft_get_line(&(buff[fd]), fd);
	if (line[0] == '\0')
	{
		ft_free(&line);
		ft_free(&(buff[fd]).begin);
		(buff[fd]).end = NULL;
		return (NULL);
	}
	return (line);
}
